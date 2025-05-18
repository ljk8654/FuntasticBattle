// Fill out your copyright notice in the Description page of Project Settings.


#include "LoomList.h"
#include "Components/ScrollBox.h"
#include "Components/Button.h"

void ULoomList::OnRoomSelected(const FString& RoomName)
{
    UE_LOG(LogTemp, Log, TEXT("방 입장: %s"), *RoomName);
    OnEnterRoomSuccess.Broadcast();
 
}

void ULoomList::OnCreateRoomClicked()
{
     FString NewRoomName = FString::Printf(TEXT("Room %d"), RoomCounter++);
    AddRoom(NewRoomName);
}

void ULoomList::NativeConstruct()
{
  Super::NativeConstruct();

    if (CreateRoomButton)
    {
        CreateRoomButton->OnClicked.AddDynamic(this, &ULoomList::OnCreateRoomClicked);
    }  

    AddRoom(TEXT("Alpha Room"));
    AddRoom(TEXT("Beta Room"));
}

void ULoomList::AddRoom(const FString& RoomName)
{
    URoomButton* NewRoom = CreateWidget<URoomButton>(this, RoomButtonClass);
    if (NewRoom)
    {
        NewRoom->Setup(RoomName);
        NewRoom->OnClicked.AddDynamic(this, &ULoomList::OnRoomSelected);
        RoomListBox->AddChild(NewRoom);
    }
}
