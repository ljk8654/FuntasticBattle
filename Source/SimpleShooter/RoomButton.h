// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RoomButton.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRoomClicked, int32, RoomId);

UCLASS()
class SIMPLESHOOTER_API URoomButton : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	void Setup(const FString& InName, int32 InRoomId);

	UPROPERTY(BlueprintAssignable)
	FOnRoomClicked OnClicked;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound")
    USoundBase* ClickSound;
protected:
    UPROPERTY(meta = (BindWidget))
    class UButton* RoomButton;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* RoomNameText;

private:
    FString RoomName;
    int32   RoomId = 0;

    UFUNCTION()
    void HandleClick();
};
