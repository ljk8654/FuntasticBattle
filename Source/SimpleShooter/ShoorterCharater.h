// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShoorterCharater.generated.h"

class AGun;
class Atestactor;
class AMeleeWeapon;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Stun")
float RagdollRecoverTime = 3.f;

private:
void MoveForward(float AxisValue);
void StartSprint();
void StopSprint();
void MoveSide(float AxisValue);
void LookUpRate(float AxisValue);
void PunchAttack();
void GunMode();
void EquipBat();
void EquipHockey();
void EquipWeapon(TSubclassOf<AMeleeWeapon> NewWeaponClass);

UFUNCTION()
void EnterRagdoll();

UFUNCTION()
void ExitRagdoll();



bool bIsRagdoll = false;
bool bHasTriggeredStun = false;
FRotator SavedActorRotation;

	int ItemMode = 0;
	float fast = 0.5;
	bool running = false;
	float AmountDamage = 0.0f;
	float AmountStunDamage = 0.0f;
	float AmountForce = 0.0f;

	UPROPERTY(EditAnywhere)
	float PlayerDamage = 10.0f;

	UPROPERTY(EditAnywhere)
	float PlayerStunDamage = 10.0f;

	UPROPERTY(EditAnywhere)
	float PlayerForce = 1000.0f;

	UPROPERTY(EditAnywhere)
	float RotationRate = 10;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	UPROPERTY(EditDefaultsOnly)
	float MaxStamina = 100;

	UPROPERTY(EditDefaultsOnly)
	float MaxStunGage = 100;
	
	UPROPERTY(EditDefaultsOnly)
	float StunDamage = 10;
	
	UPROPERTY(EditDefaultsOnly)
	float ChaForce = 100;
	

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMeleeWeapon> BatClass;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMeleeWeapon> HockeyClass;

	UPROPERTY()
	AGun* Gun;

	UPROPERTY()
	Atestactor* Bat;

	UPROPERTY()
	AMeleeWeapon* MeleeWeapon;
};