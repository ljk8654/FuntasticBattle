// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocationIfSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"


UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = TEXT("Update Player Location If Seen");
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp,NodeMemory,DeltaSeconds);
    
    APawn *PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(),0);
   
    if(PlayerPawn == nullptr)
    {
        return;
    }

    if(OwnerComp.GetAIOwner() == nullptr)
    {
        return;
    }
    APawn* AIPawn = OwnerComp.GetAIOwner()->GetPawn();

	if (AIPawn == nullptr) return;
    FVector DirectionToPlayer = PlayerPawn->GetActorLocation() - AIPawn->GetActorLocation();
	float Distance = DirectionToPlayer.Size();

	// 거리 확인
	if (Distance > SightRadius)
	{
		OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
		return;
	}

	// 각도 확인
	DirectionToPlayer.Normalize();
	FVector Forward = AIPawn->GetActorForwardVector();
	float Dot = FVector::DotProduct(Forward, DirectionToPlayer);

	// Dot > cos(각도) : 시야 각도 안에 있음
	float CosSightAngle = FMath::Cos(FMath::DegreesToRadians(SightAngle));
	if (Dot > CosSightAngle)
	{
		// LineOfSight도 확인하면 좋음
		if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
			return;
		}
	}

	OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
}
