// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AGun::PullTrigger()
{	// 효과설정
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash,Mesh,TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh,TEXT("MuzzleFlashSocket"));
	FHitResult Hit;
	FVector ShotDirection;
	bool bSuccess = GunTrace(Hit, ShotDirection);
	if (bSuccess)
	{
		//소리 붙이기
		//DrawDebugPoint(GetWorld(),Hit.Location,2,FColor::Red,true);
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),ImpactEffect,Hit.Location, ShotDirection.Rotation());
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ImpactSound, Hit.Location);
		AActor* HitActor = Hit.GetActor();
		if(HitActor != nullptr)
		{
			FPointDamageEvent DamageEvent(Damage, Hit, ShotDirection, nullptr);
			AController *OwnerController = GetOwnerController();
			HitActor->TakeDamage(Damage,DamageEvent,OwnerController, this);
		}
	}
	//DrawDebugCamera(GetWorld(), Location,Rotation, 90, 2, FColor::Red, true);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGun::GunTrace(FHitResult& Hit, FVector& ShotDirection)
{
	AController *OwnerController = GetOwnerController();
	if(OwnerController == nullptr)
	 return false;

	FVector Location;
	FRotator Rotation;
	OwnerController->GetPlayerViewPoint(Location,Rotation);
	ShotDirection = -Rotation.Vector();

	FVector End = Location + Rotation.Vector() * MaxRange;
	// TODO: LineTrace
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());
	return GetWorld() -> LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1,Params);
	
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	   if (OwnerPawn)
    {
        return OwnerPawn->GetController();
    }
    return nullptr;
}