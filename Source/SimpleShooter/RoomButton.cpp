// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomButton.h"



void URoomButton::Setup(const FString& InRoomName)
{
     RoomName = InRoomName;
    if (RoomNameText)
    {
        RoomNameText->SetText(FText::FromString(RoomName));
    }
}

void URoomButton::HandleClick()
{
    OnClicked.Broadcast(RoomName);
}

void URoomButton::NativeConstruct()
{
    Super::NativeConstruct();

    if (RoomButton)
    {
        RoomButton->OnClicked.AddDynamic(this, &URoomButton::HandleClick);
    }
}
