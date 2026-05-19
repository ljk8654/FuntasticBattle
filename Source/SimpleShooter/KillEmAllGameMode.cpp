// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"


void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    // 네트워크 게임에서는 서버가 SC_GAME_END로 게임 종료를 처리
}

void AKillEmAllGameMode::BeginPlay()
{
    Super::BeginPlay();
    UGameplayStatics::SetGamePaused(GetWorld(), true);
    if (BackgroundMusic)
    {
        UGameplayStatics::PlaySound2D(this, BackgroundMusic);
    }
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
    for(AController* Controller : TActorRange<AController>(GetWorld()))
    {
       // bool bIsPlayerWineer =  Controller->IsPlayerController();
       // if(bIsPlayerWineer)
       // {
       //     Controller->GameHasEnded(nullptr,bIsPlayerController);    
       // }
       // else
       // {
       //     Controller->GameHasEnded(nullptr,!bIsPlayerController);
       // }
       bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
       Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
    }
}

