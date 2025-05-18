// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RoomButton.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomClicked, const FString&, RoomName);

UCLASS()
class SIMPLESHOOTER_API URoomButton : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	void Setup(const FString& InRoomName);

	UPROPERTY(BlueprintAssignable)
	FOnRoomClicked OnClicked;

protected:
    UPROPERTY(meta = (BindWidget))
    class UButton* RoomButton;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* RoomNameText;
	
private:
    FString RoomName;

    UFUNCTION()
    void HandleClick();
};
