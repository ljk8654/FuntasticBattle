// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShoorterCharater.generated.h"

class AGun;
class Atestactor;

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

	UFUNCTION(BlueprintPure)
	float HealthPercent() const;

	UFUNCTION(BlueprintPure)
	float StaminaPercent() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void Shoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySettings")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MySettings")
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UAnimMontage* HitMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	UAnimMontage* JumpMontage;

private:
void MoveForward(float AxisValue);
void StartSprint();
void StopSprint();
void MoveSide(float AxisValue);
void LookUpRate(float AxisValue);
void PunchAttack();

float fast = 0.5;
bool running = false;
	UPROPERTY(EditAnywhere)
	float RotationRate = 10;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	UPROPERTY(EditDefaultsOnly)
	float MaxStamina = 100;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<Atestactor> BatClass;

	UPROPERTY()
	AGun* Gun;

	UPROPERTY()
	Atestactor* Bat;
};