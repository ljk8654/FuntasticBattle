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

    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        Net->OnEnterGame.AddDynamic(this, &ULoomList::OnEnterGameReceived);
        Net->OnRoomListUpdate.AddDynamic(this, &ULoomList::OnRoomListReceived);
    }
}

void ULoomList::OnCreateRoomClicked()
{
    if (ClickSound)
        UGameplayStatics::PlaySound2D(this, ClickSound);

    UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
    if (Net && Net->IsConnected())
    {
        FString NewRoomName = FString::Printf(TEXT("방 %d"), RoomCounter++);
        Net->SendCreateRoom(NewRoomName);
    }
}

void ULoomList::OnRoomSelected(int32 RoomId)
{
    UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
    if (Net && Net->IsConnected())
    {
        Net->SendEnterRoom(static_cast<uint32>(RoomId));
    }
    else
    {
        OnEnterRoomSuccess.Broadcast();
    }
}

void ULoomList::OnEnterGameReceived(int64 MyPlayerId, int32 OtherCount, bool bIsOwner)
{
    UE_LOG(LogTemp, Log, TEXT("방 입장 완료 playerId=%lld 기존인원=%d 방장=%d"), MyPlayerId, OtherCount, bIsOwner);
    OnEnterRoomSuccess.Broadcast();
}

void ULoomList::OnRoomListReceived(TArray<FRoomInfo> Rooms)
{
    if (!RoomListBox) return;

    // 기존 버튼 전부 제거
    RoomListBox->ClearChildren();

    // 수신된 방 목록으로 버튼 생성
    for (const FRoomInfo& Room : Rooms)
    {
        AddRoom(Room.Name, Room.RoomId);
    }
}

void ULoomList::AddRoom(const FString& Name, int32 RoomId)
{
    if (!RoomButtonClass || !RoomListBox) return;

    URoomButton* NewRoom = CreateWidget<URoomButton>(GetOwningPlayer(), RoomButtonClass);
    if (NewRoom)
    {
        NewRoom->Setup(Name, RoomId);
        NewRoom->OnClicked.AddDynamic(this, &ULoomList::OnRoomSelected);
        RoomListBox->AddChild(NewRoom);
    }
}
