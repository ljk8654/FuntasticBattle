// Fill out your copyright notice in the Description page of Project Settings.

#include "PoisonGas.h"
#include "Components/SphereComponent.h"
#include "NiagaraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

APoisonGas::APoisonGas()
{
    PrimaryActorTick.bCanEverTick = true;

    GasCollision = CreateDefaultSubobject<USphereComponent>(TEXT("GasCollision"));
    RootComponent = GasCollision;
    GasCollision->SetSphereRadius(OuterRadius);
    GasCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    GasCollision->OnComponentBeginOverlap.AddDynamic(this, &APoisonGas::OnBeginOverlap);
    GasCollision->OnComponentEndOverlap.AddDynamic(this, &APoisonGas::OnEndOverlap);

    GasFX = CreateDefaultSubobject<UNiagaraComponent>(TEXT("GasFX"));
    GasFX->SetupAttachment(RootComponent);
}

void APoisonGas::BeginPlay()
{
    Super::BeginPlay();
    GetWorldTimerManager().SetTimer(DamageTimerHandle, this, &APoisonGas::ApplyGasDamage,
                                    DamageInterval, true);
}

void APoisonGas::Tick(float Delta)
{
    Super::Tick(Delta);

    // Shrink outer radius over time
    OuterRadius = FMath::Max(InnerRadius, OuterRadius - ShrinkRate * Delta);
    GasCollision->SetSphereRadius(OuterRadius);

    // Update Niagara user parameter to tighten effect inward
    if (GasFX)
    {
        GasFX->SetVariableFloat(TEXT("User.OuterRadius"), OuterRadius);
    }
}

void APoisonGas::OnBeginOverlap(UPrimitiveComponent* /*Comp*/, AActor* OtherActor,
                                UPrimitiveComponent* /*OtherComp*/, int32 /*Idx*/, bool /*Sweep*/,
                                const FHitResult& /*SweepResult*/)
{
    if (OtherActor && OtherActor->IsA<ACharacter>())
    {
        OverlappingActors.Add(OtherActor);
    }
}

void APoisonGas::OnEndOverlap(UPrimitiveComponent* /*Comp*/, AActor* OtherActor,
                              UPrimitiveComponent* /*OtherComp*/, int32 /*Idx*/)
{
    OverlappingActors.Remove(OtherActor);
}

void APoisonGas::ApplyGasDamage()
{
    const FVector Center = GetActorLocation();
    for (AActor* Victim : OverlappingActors)
    {
        if (!IsValid(Victim))
            continue;

        const float Dist = FVector::Dist(Center, Victim->GetActorLocation());
        // Damage only actors outside the shrinking radius
        if (Dist > OuterRadius)
        {
            UGameplayStatics::ApplyDamage(Victim, DamagePerTick, nullptr, this,
                                          UDamageType::StaticClass());
        }
    }
}
