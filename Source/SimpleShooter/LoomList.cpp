#include "LoomList.h"
#include "RoomButton.h"

#include "Components/ScrollBox.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void ULoomList::NativeConstruct()
{
    Super::NativeConstruct();

    if (CreateRoomButton)
    {
        CreateRoomButton->OnClicked.AddDynamic(
            this,
            &ULoomList::OnCreateRoomClicked
        );
    }

    AddRoom(TEXT("Alpha Room"));
    AddRoom(TEXT("Beta Room"));
}

void ULoomList::OnCreateRoomClicked()
{
    if (ClickSound)
    {
        UGameplayStatics::PlaySound2D(this, ClickSound);
    }

    FString NewRoomName = FString::Printf(TEXT("Room %d"), RoomCounter++);
    AddRoom(NewRoomName);
}

void ULoomList::OnRoomSelected(const FString& RoomName)
{
    UE_LOG(LogTemp, Log, TEXT("방 입장: %s"), *RoomName);
    OnEnterRoomSuccess.Broadcast();
}

void ULoomList::AddRoom(const FString& RoomName)
{
    if (!RoomButtonClass || !RoomListBox) return;

    URoomButton* NewRoom = CreateWidget<URoomButton>(
        GetOwningPlayer(),
        RoomButtonClass
    );

    if (NewRoom)
    {
        NewRoom->Setup(RoomName);
        NewRoom->OnClicked.AddDynamic(this, &ULoomList::OnRoomSelected);
        RoomListBox->AddChild(NewRoom);
    }
}
