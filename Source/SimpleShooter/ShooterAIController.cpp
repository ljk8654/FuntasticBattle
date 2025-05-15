// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ShoorterCharater.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    APawn*  PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);

    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);

       GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
    
    }
}

void AShooterAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    APawn*  PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
   // if(LineOfSightTo(PlayerPawn))
   // {
    //    SetFocus(PlayerPawn);
    //    MoveToActor(PlayerPawn, AcceptanceRadius);
     //   GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());
    //    GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"), PlayerPawn->GetActorLocation());
    //} 
    //else
    //{
     //  ClearFocus(EAIFocusPriority::Gameplay);
     //   StopMovement();
     //   GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
   // }
}

bool AShooterAIController::IsDead() const
{
    AShoorterCharater* ControlledCharacter = Cast<AShoorterCharater>(GetPawn());
    if (ControlledCharacter != nullptr)
    {
        return ControlledCharacter->IsDead();
    }

    return true;
}
