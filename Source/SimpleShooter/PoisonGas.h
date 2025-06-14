// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class USphereComponent;
class UNiagaraComponent;

#include "PoisonGas.generated.h"

UCLASS()
class SIMPLESHOOTER_API APoisonGas : public AActor
{
    GENERATED_BODY()

public:
    APoisonGas();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float Delta) override;

    /** Outer radius of the gas sphere */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoisonGas|Shrink")
    float OuterRadius = 1000.f;

    /** Inner radius (safe zone) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoisonGas|Shrink")
    float InnerRadius = 200.f;

    /** Shrink rate (units per second) */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoisonGas|Shrink")
    float ShrinkRate = 50.f;

    /** Collision component for detection */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PoisonGas")
    USphereComponent* GasCollision;

    /** Niagara component for visual effect */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="PoisonGas")
    UNiagaraComponent* GasFX;

    /** Timer handle for damage ticks */
    FTimerHandle DamageTimerHandle;

    /** Damage tick interval */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoisonGas|Damage")
    float DamageInterval = 1.f;

    /** Damage applied per tick */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PoisonGas|Damage")
    float DamagePerTick = 10.f;

    /** Actors tracked inside collision sphere */
    UPROPERTY()
    TSet<AActor*> OverlappingActors;

private:
    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
                        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    /** Applies damage to actors outside the shrinking sphere */
    void ApplyGasDamage();
};