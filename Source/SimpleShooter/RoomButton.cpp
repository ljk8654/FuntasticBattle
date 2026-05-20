// Fill out your copyright notice in the Description page of Project Settings.


#include "RoomButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"



void URoomButton::Setup(const FString& InName, int32 InRoomId)
{
    RoomName = InName;
    RoomId   = InRoomId;
    if (RoomNameText)
    {
        RoomNameText->SetText(FText::FromString(RoomName));
    }
}

void URoomButton::HandleClick()
{
    if (ClickSound)
    {
        UGameplayStatics::PlaySound2D(this, ClickSound);
    }

    OnClicked.Broadcast(RoomId);
}

void URoomButton::NativeConstruct()
{
    Super::NativeConstruct();

    if (RoomButton)
    {
        RoomButton->OnClicked.AddDynamic(this, &URoomButton::HandleClick);
    }
}
