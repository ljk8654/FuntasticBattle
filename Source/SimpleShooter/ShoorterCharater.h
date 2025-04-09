// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShoorterCharater.generated.h"

class AGun;

UCLASS()
class SIMPLESHOOTER_API AShoorterCharater : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShoorterCharater();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION() 
	void EnableMovement();
	
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void Shoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySettings")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UAnimMontage* HitMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UAnimMontage* AttackMontage;

private:
void MoveForward(float AxisValue);
void StartSprint();
void StopSprint();
void MoveSide(float AxisValue);
void LookUpRate(float AxisValue);
void PunchAttack();
float fast = 0.5;

	UPROPERTY(EditAnywhere)
	float RotationRate = 10;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;
};