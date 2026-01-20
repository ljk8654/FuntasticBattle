// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"
#include "ShooterPlayerController.h"
#include "HUDWidget.h"
#include "Kismet/GameplayStatics.h"

void AShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    
    if (HUD)
    {
        HUD->RemoveFromViewport();
    }

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

    // 게임 HUD 생성
    HUD = nullptr;
    if (HUDClass)
    {
        HUD = CreateWidget<UHUDWidget>(this, HUDClass);
        if (HUD)
        {
            HUD->AddToViewport();
            HUD->SetVisibility(ESlateVisibility::Hidden);
        }
    }


    // 입력/UI 모드
    SetShowMouseCursor(true);

    FInputModeUIOnly InputMode;
    SetInputMode(InputMode);

    // 게임 일시정지
    UGameplayStatics::SetGamePaused(GetWorld(), true);

    // 로그인 UI 표시
    if (LoginWidgetClass)
    {
        CurrentLoginWidget = CreateWidget<ULoginWidget>(this, LoginWidgetClass);
        if (CurrentLoginWidget)
        {
            CurrentLoginWidget->AddToViewport();
            CurrentLoginWidget->OnLoginSuccess.AddDynamic(this, &AShooterPlayerController::OnLoginSuccess);
        }
    }
}

void AShooterPlayerController::OnLoginSuccess()
{
    // 1) 로그인 UI 제거
    if (CurrentLoginWidget)
    {
        CurrentLoginWidget->RemoveFromParent();
        CurrentLoginWidget = nullptr;
    }

    // 2) 룸 리스트 표시
    if (RoomListClass)
    {
        RoomList = CreateWidget<ULoomList>(this, RoomListClass);
        if (RoomList)
        {
            RoomList->AddToViewport();
            RoomList->OnEnterRoomSuccess.AddDynamic(this, &AShooterPlayerController::OnEnterRoomSuccess);
        }
    }
}

void AShooterPlayerController::OnEnterRoomSuccess()
{
    // 게임 입력 모드로 전환
    SetShowMouseCursor(false);

    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);

    UGameplayStatics::SetGamePaused(GetWorld(), false);

    // 룸 리스트 제거
    if (RoomList)
    {
        RoomList->RemoveFromViewport();
        RoomList = nullptr;
    }

    // HUD 보이기
    if (HUD)
    {
        HUD->SetVisibility(ESlateVisibility::Visible);
    }
}