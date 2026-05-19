#include "ShooterPlayerController.h"
#include "FBNetworkSubsystem.h"
#include "RemotePlayer.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.h"
#include "Kismet/GameplayStatics.h"

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
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
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
    }
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
    SetShowMouseCursor(false);
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
    UGameplayStatics::SetGamePaused(GetWorld(), false);

    if (RoomList)
    {
        RoomList->RemoveFromParent();
        RoomList = nullptr;
    }

    if (HUD)
        HUD->SetVisibility(ESlateVisibility::Visible);

    // 입장 즉시 현재 위치를 서버에 전송 → 다른 플레이어에게 (0,0,0) 대신 실제 위치가 전달됨
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        if (APawn* MyPawn = GetPawn())
        {
            FVector Pos = MyPawn->GetActorLocation();
            float Yaw = MyPawn->GetActorRotation().Yaw;
            Net->SendMove(Pos, Yaw, FVector::ZeroVector);
        }
    }
}

void AShooterPlayerController::OnRemotePlayerEnter(int64 PlayerId, FVector InitPos, float InitYaw)
{
    if (!RemotePlayerClass) return;

    UWorld* World = GetWorld();
    if (!World) return;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    ARemotePlayer* Remote = World->SpawnActor<ARemotePlayer>(
        RemotePlayerClass,
        InitPos,
        FRotator(0.f, InitYaw, 0.f),
        Params
    );

    if (Remote)
    {
        Remote->PlayerId = PlayerId;
        Remote->SetTargetTransform(InitPos, InitYaw);
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
        // 내가 맞은 경우 → 로컬 캐릭터에 직접 데미지 적용
        if (APawn* MyPawn = GetPawn())
        {
            FDamageEvent DmgEvent;
            MyPawn->TakeDamage(Amount, DmgEvent, nullptr, nullptr);
        }
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

void AShooterPlayerController::OnRemoteItemStateReceived(int64 PlayerId, uint8 ItemType)
{
    if (ARemotePlayer** Found = RemotePlayers.Find(PlayerId))
    {
        if (*Found)
            (*Found)->SetItemState(ItemType);
    }
}

void AShooterPlayerController::OnRemoteThrowBombReceived(int64 PlayerId, FVector Pos, float Yaw)
{
    if (ARemotePlayer** Found = RemotePlayers.Find(PlayerId))
    {
        if (*Found)
            (*Found)->SpawnSyncBomb(Pos, Yaw);
    }
}
