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
    UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
    if (Net && Net->IsConnected())
    {
        Net->SendEnterRoom(1);
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
