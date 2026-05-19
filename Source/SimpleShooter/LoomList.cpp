#include "LoomList.h"
#include "RoomButton.h"
#include "FBNetworkSubsystem.h"
#include "Components/ScrollBox.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void ULoomList::NativeConstruct()
{
    Super::NativeConstruct();

    if (CreateRoomButton)
        CreateRoomButton->OnClicked.AddDynamic(this, &ULoomList::OnCreateRoomClicked);

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &ULoomList::OnStartGameClicked);
        StartGameButton->SetVisibility(ESlateVisibility::Collapsed);
    }

    // 기본 방 목록 (서버에는 roomId=1만 존재)
    AddRoom(TEXT("FuntasticBattle Room 1"));

    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        Net->OnEnterGame.AddDynamic(this, &ULoomList::OnEnterGameReceived);
        Net->OnGameStart.AddDynamic(this, &ULoomList::OnGameStartReceived);
    }
}

void ULoomList::OnCreateRoomClicked()
{
    if (ClickSound)
        UGameplayStatics::PlaySound2D(this, ClickSound);

    FString NewRoomName = FString::Printf(TEXT("Room %d"), RoomCounter++);
    AddRoom(NewRoomName);
}

void ULoomList::OnRoomSelected(const FString& RoomName)
{
    UE_LOG(LogTemp, Log, TEXT("방 입장 시도: %s"), *RoomName);

    UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
    if (Net && Net->IsConnected())
    {
        Net->SendEnterRoom(1);  // 서버에 roomId=1로 고정
    }
    else
    {
        // 네트워크 없는 로컬 모드 (서버 미연결 시)
        OnEnterRoomSuccess.Broadcast();
    }
}

void ULoomList::OnEnterGameReceived(int64 MyPlayerId, int32 OtherCount, bool bOwner)
{
    UE_LOG(LogTemp, Log, TEXT("방 입장 완료 playerId=%lld 기존인원=%d 방장=%d"), MyPlayerId, OtherCount, bOwner);
    bIsOwner = bOwner;

    // 방 목록 숨기고 대기실로 전환
    if (RoomListBox)
        RoomListBox->SetVisibility(ESlateVisibility::Collapsed);
    if (CreateRoomButton)
        CreateRoomButton->SetVisibility(ESlateVisibility::Collapsed);

    // 방장에게만 시작 버튼 표시
    if (StartGameButton)
        StartGameButton->SetVisibility(bOwner ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void ULoomList::OnStartGameClicked()
{
    if (!bIsOwner) return;

    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        if (Net->IsConnected())
            Net->SendStartGame();
    }
}

void ULoomList::OnGameStartReceived(uint8 SpawnIndex, int32 ItemSeed)
{
    // 게임 시작 — ShooterPlayerController가 OnGameStart를 직접 바인딩해 처리하므로
    // 여기서는 UI만 닫고 OnEnterRoomSuccess 브로드캐스트
    OnEnterRoomSuccess.Broadcast();
}

void ULoomList::AddRoom(const FString& RoomName)
{
    if (!RoomButtonClass || !RoomListBox) return;

    URoomButton* NewRoom = CreateWidget<URoomButton>(GetOwningPlayer(), RoomButtonClass);
    if (NewRoom)
    {
        NewRoom->Setup(RoomName);
        NewRoom->OnClicked.AddDynamic(this, &ULoomList::OnRoomSelected);
        RoomListBox->AddChild(NewRoom);
    }
}
