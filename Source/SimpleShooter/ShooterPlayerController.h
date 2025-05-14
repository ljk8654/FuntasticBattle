// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

class ULoginWidget;

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

	/** 로그인 UI 위젯 */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<ULoginWidget> LoginWidgetClass;

    /** 현재 생성된 로그인 위젯 인스턴스 */
    UPROPERTY()
    ULoginWidget* CurrentLoginWidget;

	UFUNCTION()
	void OnLoginSuccess();

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
};
