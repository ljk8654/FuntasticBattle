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

    // 기본 방 목록 (서버에는 roomId=1만 존재)
    AddRoom(TEXT("FuntasticBattle Room 1"));

    // 방 입장 성공 이벤트 바인딩
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
        Net->OnEnterGame.AddDynamic(this, &ULoomList::OnEnterGameReceived);
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

void ULoomList::OnEnterGameReceived(int64 MyPlayerId, int32 OtherCount)
{
    UE_LOG(LogTemp, Log, TEXT("방 입장 완료 playerId=%lld 기존인원=%d"), MyPlayerId, OtherCount);
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
