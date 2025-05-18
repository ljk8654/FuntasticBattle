// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    
    HUD->RemoveFromViewport();
    if (bIsWinner)
    {
        UUserWidget* WinnerScreen = CreateWidget(this, WinnerScreenClass);
        if(WinnerScreen != nullptr)
        {
            WinnerScreen->AddToViewport();
        }
    }
    else
    {
        UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
        if(LoseScreen != nullptr)
        {
            LoseScreen->AddToViewport();
        }
    }
    GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void AShooterPlayerController::BeginPlay()
{
    Super::BeginPlay();

    HUD= CreateWidget(this, HUDClass);
    if(HUD != nullptr)
    {
        HUD->AddToViewport();
    }

    // 1. 입력 비활성화
    SetShowMouseCursor(true);
    FInputModeUIOnly InputMode;
    SetInputMode(InputMode);

    // 2. 로그인 UI 표시
    if (LoginWidgetClass)
    {
        ULoginWidget* LoginUI = CreateWidget<ULoginWidget>(this, LoginWidgetClass);
        CurrentLoginWidget = LoginUI;
        if (LoginUI)
        {
            LoginUI->AddToViewport();
            LoginUI->OnLoginSuccess.AddDynamic(this, &AShooterPlayerController::OnLoginSuccess); // 커스텀 이벤트
        }
    }
}
void AShooterPlayerController::OnLoginSuccess()
{

       // 1. UI 제거
    if (CurrentLoginWidget)
    {
        CurrentLoginWidget->RemoveFromParent();
    }

    RoomList = CreateWidget<ULoomList>(this, RoomListClass);
    if(RoomList){
    RoomList->AddToViewport();
    RoomList->OnEnterRoomSuccess.AddDynamic(this, &AShooterPlayerController::OnEnterRoomSuccess);
    }
}

void AShooterPlayerController::OnEnterRoomSuccess()
{
    SetShowMouseCursor(false);
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);

    RoomList->RemoveFromViewport();
    
}