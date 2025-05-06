// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MeleeWeapon.generated.h"

UCLASS()
class SIMPLESHOOTER_API AMeleeWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeleeWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
	USoundBase* ImpactSound;

	AController* GetOwnerController() const;

public:
	UPROPERTY(EditAnywhere)
	float Damage = 10.0f;

	UPROPERTY(EditAnywhere)
	float StunDamage = 20.0f;

	UPROPERTY(EditAnywhere)
	float AddForce = 2000.0f;
};
