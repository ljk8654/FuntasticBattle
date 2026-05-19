// Fill out your copyright notice in the Description page of Project Settings.

#include "Heart.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ShoorterCharater.h"
#include "FBNetworkSubsystem.h"

AHeart::AHeart()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(Root);
	Sphere->SetSphereRadius(60.f);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Sphere->SetCollisionResponseToAllChannels(ECR_Ignore);
	Sphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

void AHeart::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AHeart::OnOverlapBegin);
}

void AHeart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 1) 회전
	AddActorLocalRotation(FRotator(0.f, RotateSpeedDegPerSec * DeltaTime, 0.f));

	// 2) 둥둥(사인파)
	RunningTime += DeltaTime;
	const float OffsetZ = FMath::Sin(RunningTime * FloatSpeed) * FloatAmplitude;
	SetActorLocation(StartLocation + FVector(0,0,OffsetZ));
}

void AHeart::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                           UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                           bool bFromSweep, const FHitResult& SweepResult)
{
	AShoorterCharater* Player = Cast<AShoorterCharater>(OtherActor);
	if (!Player || !Player->IsPlayerControlled()) return;

	if (Player->Heal(HealAmount))
	{
		// 다른 클라이언트에 픽업 동기화
		if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
		{
			if (Net->IsConnected())
				Net->SendItemPickup(GetActorLocation());
		}
		Destroy();
	}
}