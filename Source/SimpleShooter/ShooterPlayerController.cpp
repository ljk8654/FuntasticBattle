#include "ShooterPlayerController.h"
#include "FBNetworkSubsystem.h"
#include "RemotePlayer.h"
#include "ShoorterCharater.h"
#include "Heart.h"
#include "Bomb.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "Engine/DamageEvents.h"

void AShooterPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindKey(EKeys::Escape, IE_Pressed, this, &AShooterPlayerController::ExitGame);
}

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus, bIsWinner);

    if (HUD)
        HUD->RemoveFromParent();

    if (bIsWinner)
    {
        UUserWidget* WinnerScreen = CreateWidget(this, WinnerScreenClass);
        if (WinnerScreen) WinnerScreen->AddToViewport();
    }
    else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if (LoseScreen) LoseScreen->AddToViewport();
    }

    // 방 퇴장 후 레벨 재시작, CurrentRoomId는 재입장용으로 유지
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        int32 SavedRoomId = Net->GetCurrentRoomId();
        Net->SendLeaveRoom();           // CS_LEAVE_ROOM 전송 (CurrentRoomId = 0으로 초기화됨)
        Net->CurrentRoomId = SavedRoomId; // 레벨 재시작 후 재입장에 쓸 방 ID 복원
    }

    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // HUD 생성
    if (HUDClass)
    {
        HUD = CreateWidget<UHUDWidget>(this, HUDClass);
        if (HUD)
        {
            HUD->AddToViewport();
            HUD->SetVisibility(ESlateVisibility::Hidden);
        }
    }

    SetShowMouseCursor(true);
    FInputModeUIOnly InputMode;
    SetInputMode(InputMode);
    UGameplayStatics::SetGamePaused(GetWorld(), true);

    // 게임 종료 후 재입장: 로그인 없이 바로 방으로 복귀
    UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
    if (Net && Net->IsConnected() && Net->GetMyPlayerId() != 0 && Net->GetCurrentRoomId() != 0)
    {
        Net->SendEnterRoom(static_cast<uint32>(Net->GetCurrentRoomId()));
        return;
    }

    // 로그인 UI
    if (LoginWidgetClass)
    {
        CurrentLoginWidget = CreateWidget<ULoginWidget>(this, LoginWidgetClass);
        if (CurrentLoginWidget)
        {
            CurrentLoginWidget->AddToViewport();
            CurrentLoginWidget->OnLoginSuccess.AddDynamic(this, &AShooterPlayerController::OnLoginSuccess);
        }
    }

    // 네트워크 이벤트 바인딩
    if (Net)
    {
        Net->OnRemotePlayerEnter.AddDynamic(this, &AShooterPlayerController::OnRemotePlayerEnter);
        Net->OnRemotePlayerLeave.AddDynamic(this, &AShooterPlayerController::OnRemotePlayerLeave);
        Net->OnRemotePlayerMove.AddDynamic(this, &AShooterPlayerController::OnRemotePlayerMove);
        Net->OnRemotePlayerAnim.AddDynamic(this, &AShooterPlayerController::OnRemoteAnimState);
        Net->OnHit.AddDynamic(this, &AShooterPlayerController::OnHitReceived);
        Net->OnGameEnd.AddDynamic(this, &AShooterPlayerController::OnGameEndReceived);
        Net->OnDisconnected.AddDynamic(this, &AShooterPlayerController::OnServerDisconnected);
        Net->OnRemoteItemState.AddDynamic(this, &AShooterPlayerController::OnRemoteItemStateReceived);
        Net->OnRemoteThrowBomb.AddDynamic(this, &AShooterPlayerController::OnRemoteThrowBombReceived);
        Net->OnRemoteItemDrop.AddDynamic(this, &AShooterPlayerController::OnRemoteItemDropReceived);
        Net->OnRemoteItemPickup.AddDynamic(this, &AShooterPlayerController::OnRemoteItemPickupReceived);
        Net->OnEnterGame.AddDynamic(this, &AShooterPlayerController::OnEnterGameReceived);
        Net->OnGameStart.AddDynamic(this, &AShooterPlayerController::OnGameStartReceived);
        Net->OnCharCustomize.AddDynamic(this, &AShooterPlayerController::OnCharCustomizeReceived);
    }
}

void AShooterPlayerController::ExitGame()
{
    UE_LOG(LogTemp, Warning, TEXT("ESC Pressed - ExitGame Called"));
    UKismetSystemLibrary::QuitGame(
        GetWorld(),
        nullptr,
        EQuitPreference::Quit,
        false
    );
}

void AShooterPlayerController::OnLoginSuccess()
{
    if (CurrentLoginWidget)
    {
        CurrentLoginWidget->RemoveFromParent();
        CurrentLoginWidget = nullptr;
    }

    if (RoomListClass)
    {
        RoomList = CreateWidget<ULoomList>(this, RoomListClass);
        if (RoomList)
        {
            RoomList->AddToViewport();
            RoomList->OnEnterRoomSuccess.AddDynamic(this, &AShooterPlayerController::OnEnterRoomSuccess);
        }
    }
}

void AShooterPlayerController::OnEnterRoomSuccess()
{
    // 방 선택 화면 닫기
    if (RoomList)
    {
        RoomList->RemoveFromParent();
        RoomList = nullptr;
    }

    // 대기방: 이동 가능 + UI 버튼 클릭도 가능하도록 GameAndUI 모드
    UGameplayStatics::SetGamePaused(GetWorld(), false);
    SetShowMouseCursor(true);
    FInputModeGameAndUI InputMode;
    InputMode.SetHideCursorDuringCapture(false);
    InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    SetInputMode(InputMode);

    // 대기 UI 표시 (방장이면 시작 버튼 보임)
    if (WaitingRoomWidgetClass)
    {
        WaitingRoomWidget = CreateWidget<UWaitingRoomWidget>(this, WaitingRoomWidgetClass);
        if (WaitingRoomWidget)
        {
            WaitingRoomWidget->AddToViewport();
            WaitingRoomWidget->SetOwnerMode(bIsOwner);
        }
    }

    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        if (APawn* MyPawn = GetPawn())
        {
            FVector Pos = MyPawn->GetActorLocation();
            float Yaw = MyPawn->GetActorRotation().Yaw;
            Net->SendMove(Pos, Yaw, FVector::ZeroVector);
            Net->SendItemState(1);
        }
    }
}

void AShooterPlayerController::OnRemotePlayerEnter(int64 PlayerId, FVector InitPos, float InitYaw, uint8 ColorIndex, uint8 MeshIndex)
{
    if (!RemotePlayerClass) return;

    UWorld* World = GetWorld();
    if (!World) return;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    // 내 슬롯을 건너뛰어 RemotePlayer 슬롯 결정
    while (RemoteWaitSlotCounter == MyWaitSlotIndex)
        RemoteWaitSlotCounter++;
    int32 RemoteSlot = RemoteWaitSlotCounter++;

    // WaitPlayer 태그 PlayerStart 위치 탐색
    FVector SpawnPos = InitPos;
    float SpawnYaw = InitYaw;
    {
        FName TagName = FName(*FString::Printf(TEXT("WaitPlayer%d"), RemoteSlot + 1));
        TArray<AActor*> Starts;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), Starts);
        for (AActor* Actor : Starts)
        {
            APlayerStart* PS = Cast<APlayerStart>(Actor);
            if (PS && PS->PlayerStartTag == TagName)
            {
                SpawnPos = PS->GetActorLocation();
                SpawnYaw = PS->GetActorRotation().Yaw;
                break;
            }
        }
    }

    ARemotePlayer* Remote = World->SpawnActor<ARemotePlayer>(
        RemotePlayerClass,
        SpawnPos,
        FRotator(0.f, SpawnYaw, 0.f),
        Params
    );

    if (Remote)
    {
        Remote->PlayerId = PlayerId;
        Remote->SetTargetTransform(SpawnPos, SpawnYaw);
        Remote->ApplyCustomization(ColorIndex, MeshIndex);
        RemotePlayers.Add(PlayerId, Remote);
        UE_LOG(LogTemp, Log, TEXT("[Controller] 원격 플레이어 스폰 id=%lld"), PlayerId);
    }
}

void AShooterPlayerController::OnRemotePlayerLeave(int64 PlayerId)
{
    if (ARemotePlayer** Found = RemotePlayers.Find(PlayerId))
    {
        if (*Found)
            (*Found)->Destroy();
        RemotePlayers.Remove(PlayerId);
        UE_LOG(LogTemp, Log, TEXT("[Controller] 원격 플레이어 제거 id=%lld"), PlayerId);
    }
}

void AShooterPlayerController::OnRemotePlayerMove(int64 PlayerId, FVector NewPos, float NewYaw, FVector NewVel)
{
    if (ARemotePlayer** Found = RemotePlayers.Find(PlayerId))
    {
        if (*Found)
            (*Found)->SetTargetTransform(NewPos, NewYaw, NewVel);
    }
}

void AShooterPlayerController::OnRemoteAnimState(int64 PlayerId, uint8 State)
{
    if (ARemotePlayer** Found = RemotePlayers.Find(PlayerId))
    {
        if (*Found)
            (*Found)->ApplyAnimState(State);
    }
}

void AShooterPlayerController::OnHitReceived(int64 AttackerId, int64 TargetId, float Amount, float RemainHp)
{
    UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
    if (!Net) return;

    if (TargetId == Net->GetMyPlayerId())
    {
        AShoorterCharater* MyChar = Cast<AShoorterCharater>(GetPawn());
        if (!MyChar) return;

        // TakeDamage로 기절/래그돌 등 부가 효과 처리
        FDamageEvent DmgEvent;
        MyChar->TakeDamage(Amount, DmgEvent, nullptr, nullptr);

        // 서버 RemainHp(0~100)로 클라이언트 체력 강제 동기화
        // MaxHealth가 Blueprint에서 어떤 값이든 서버 기준으로 맞춤
        float Normalized = FMath::Clamp(RemainHp / 100.f, 0.f, 1.f);
        MyChar->Health = Normalized * MyChar->MaxHealth;

        // HUD도 서버 기준으로 업데이트
        if (UHUDWidget* HUD = GetHUDWidget())
            HUD->SetHpNormalized(Normalized);
    }
}

void AShooterPlayerController::OnGameEndReceived(int64 WinnerId, bool bIsWinner)
{
    GameHasEnded(nullptr, bIsWinner);
}

void AShooterPlayerController::OnServerDisconnected()
{
    UE_LOG(LogTemp, Warning, TEXT("[Network] 서버 연결 끊김 — RemotePlayer 정리"));

    for (auto& [Id, Remote] : RemotePlayers)
    {
        if (Remote)
            Remote->Destroy();
    }
    RemotePlayers.Empty();
}

void AShooterPlayerController::OnRemoteItemDropReceived(uint8 ItemType, FVector Pos)
{
    UWorld* World = GetWorld();
    if (!World) return;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    switch (ItemType)
    {
    case 1:
        if (HeartDropClass)
            World->SpawnActor<AHeart>(HeartDropClass, Pos, FRotator::ZeroRotator, Params);
        break;
    case 2:
        if (BombDropClass)
            World->SpawnActor<ABomb>(BombDropClass, Pos + FVector(20.f, 0.f, 10.f), FRotator::ZeroRotator, Params);
        break;
    }
}

void AShooterPlayerController::OnRemoteItemPickupReceived(FVector Pos)
{
    // 해당 위치 근처의 Heart를 제거
    TArray<AActor*> HeartActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHeart::StaticClass(), HeartActors);
    for (AActor* Actor : HeartActors)
    {
        if (FVector::Dist(Actor->GetActorLocation(), Pos) < 150.f)
        {
            Actor->Destroy();
            return;
        }
    }
}

void AShooterPlayerController::OnRemoteItemStateReceived(int64 PlayerId, uint8 ItemType)
{
    if (ARemotePlayer** Found = RemotePlayers.Find(PlayerId))
    {
        if (*Found)
            (*Found)->SetItemState(ItemType);
    }
}

void AShooterPlayerController::OnCharCustomizeReceived(int64 PlayerId, uint8 ColorIndex, uint8 MeshIndex)
{
    UE_LOG(LogTemp, Warning, TEXT("[커스터마이즈] playerId=%lld color=%d mesh=%d RemotePlayers 수=%d"),
        PlayerId, ColorIndex, MeshIndex, RemotePlayers.Num());

    if (ARemotePlayer** Found = RemotePlayers.Find(PlayerId))
    {
        if (*Found)
            (*Found)->ApplyCustomization(ColorIndex, MeshIndex);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("[커스터마이즈] playerId=%lld 를 RemotePlayers에서 찾지 못함"), PlayerId);
    }
}

void AShooterPlayerController::OnEnterGameReceived(int64 MyPlayerId, int32 OtherCount, bool bOwner)
{
    bIsOwner = bOwner;
    MyWaitSlotIndex = OtherCount;
    RemoteWaitSlotCounter = 0;
    UE_LOG(LogTemp, Warning, TEXT("[OnEnterGame] PlayerId=%lld OtherCount=%d bIsOwner=%d WaitSlot=%d"),
        MyPlayerId, OtherCount, bIsOwner, MyWaitSlotIndex);

    // 게임 종료 후 재입장: LoomList가 없으므로 직접 대기방으로 복귀
    if (RoomList == nullptr && WaitingRoomWidget == nullptr)
    {
        OnEnterRoomSuccess();
    }
}

void AShooterPlayerController::OnGameStartReceived(uint8 SpawnIndex, int32 ItemSeed)
{
    // 대기방 카메라 복원 (방장은 OnStartGameClicked에서 이미 호출, 비방장은 여기서 호출)
    if (AShoorterCharater* PlayerCharacter = Cast<AShoorterCharater>(GetPawn()))
        PlayerCharacter->ExitWaitingRoomView();

    // 대기 UI 닫기
    if (WaitingRoomWidget)
    {
        WaitingRoomWidget->RemoveFromParent();
        WaitingRoomWidget = nullptr;
    }

    // 게임 입력 모드로 전환 (커서 숨김)
    SetShowMouseCursor(false);
    FInputModeGameOnly GameInput;
    SetInputMode(GameInput);

    // 게임 HUD 표시
    if (HUD)
        HUD->SetVisibility(ESlateVisibility::Visible);

    // PlayerStart 배열에서 SpawnIndex에 해당하는 위치로 이동
    TArray<AActor*> StartPoints;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), StartPoints);

    if (StartPoints.Num() > 0)
    {
        int32 Idx = SpawnIndex % StartPoints.Num();
        FVector SpawnPos = StartPoints[Idx]->GetActorLocation();
        float   SpawnYaw = StartPoints[Idx]->GetActorRotation().Yaw;

        if (APawn* MyPawn = GetPawn())
        {
            MyPawn->SetActorLocation(SpawnPos, false, nullptr, ETeleportType::TeleportPhysics);
            MyPawn->SetActorRotation(FRotator(0.f, SpawnYaw, 0.f));
        }
    }

    // 방장만 아이템 스폰 후 서버로 전송
    if (bIsOwner)
    {
        UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
        if (Net && Net->IsConnected() && ItemDropSpawnPoints.Num() > 0)
        {
            FMath::RandInit(ItemSeed);
            int32 DropCount = FMath::Min(3, ItemDropSpawnPoints.Num());
            TArray<int32> Indices;
            for (int32 i = 0; i < ItemDropSpawnPoints.Num(); i++) Indices.Add(i);

            for (int32 i = 0; i < DropCount; i++)
            {
                int32 Pick = FMath::RandRange(i, Indices.Num() - 1);
                Indices.Swap(i, Pick);
                uint8 DropType = (i % 2 == 0) ? 1 : 2;
                Net->SendItemDrop(DropType, ItemDropSpawnPoints[Indices[i]]);
            }
        }
    }
}

void AShooterPlayerController::OnRemoteThrowBombReceived(int64 PlayerId, FVector Pos, float Yaw, float Pitch)
{
    if (ARemotePlayer** Found = RemotePlayers.Find(PlayerId))
    {
        if (*Found)
            (*Found)->SpawnSyncBomb(Pos, Yaw, Pitch);
    }
}
