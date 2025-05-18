// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoomList.generated.h"

class URoomButton;

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnterRoomSuccess);
UCLASS()
class SIMPLESHOOTER_API ULoomList : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

	void AddRoom(const FString& RoomName);

	FOnEnterRoomSuccess OnEnterRoomSuccess;

protected:
    UPROPERTY(meta = (BindWidget))
    class UScrollBox* RoomListBox;

    UPROPERTY(meta = (BindWidget))
    class UButton* CreateRoomButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<URoomButton> RoomButtonClass;

	int RoomCounter = 1;

	UFUNCTION()
	void OnCreateRoomClicked();

	UFUNCTION()
	void OnRoomSelected(const FString& RoomName);
	
};
