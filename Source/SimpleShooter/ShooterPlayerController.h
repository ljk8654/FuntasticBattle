// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

class ULoginWidget;
class ULoomList;

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<ULoginWidget> LoginWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<ULoomList> RoomListClass;

    UPROPERTY()
    ULoginWidget* CurrentLoginWidget;

	UFUNCTION()
	void OnLoginSuccess();
	
	UFUNCTION()
	void OnEnterRoomSuccess();


protected:
	virtual void BeginPlay() override;
	

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf <class UUserWidget> HUDClass;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf <class UUserWidget> WinnerScreenClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf <class UUserWidget> LoseScreenClass;

	UPROPERTY(EditAnywhere)
	float RestartDelay = 5;

	FTimerHandle RestartTimer;

	UPROPERTY()
	UUserWidget* HUD;

	UPROPERTY()
	ULoomList* RoomList;
};
