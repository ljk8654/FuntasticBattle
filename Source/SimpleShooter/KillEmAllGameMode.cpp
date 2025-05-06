// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    
    APlayerController* PlayerController =  Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false);
    }

    // 월드에서 죽은 ai 세기
        // 안죽었니?
            // 리턴
    for (AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld()))
    {
        if (!AIController->IsDead())
        {
            return;
        }
    }
    EndGame(true);
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