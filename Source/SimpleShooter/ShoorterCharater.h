// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShoorterCharater.generated.h"

class AGun;
class Atestactor;
class AMeleeWeapon;
class AShooterPlayerController;
class UHUDWidget;
class ABomb;
class AHeart;

UENUM(BlueprintType)
enum class ECharState : uint8
{
    Normal     UMETA(DisplayName = "Normal"),
    Hit        UMETA(DisplayName = "Hit"),
    Stunned    UMETA(DisplayName = "Stunned"),
    Recover    UMETA(DisplayName = "Recover")
};


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
	void PickupBomb(class ABomb* Bomb);

    void ThrowBomb();

 	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="State")
    ECharState CurrentState = ECharState::Normal;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsAttacking = false;
	
	UFUNCTION() 
	void EnableMovement();
	
	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintCallable, Category="MySettings")
	bool Heal(float Amount);

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

	
	void PunchAttack();

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

	UPROPERTY(EditDefaultsOnly, Category="Drop")
	bool bEnableDropOnDeath = false; // NPC BP에서만 true로

	UPROPERTY(EditDefaultsOnly, Category="Drop")
	TSubclassOf<AHeart> HeartDropClass;

	UPROPERTY(EditDefaultsOnly, Category="Drop", meta=(ClampMin="0.0", ClampMax="1.0"))
	float HeartDropChance = 0.5f;

	UPROPERTY(EditDefaultsOnly, Category="Drop")
	TSubclassOf<ABomb> BombDropClass;

	UPROPERTY(EditDefaultsOnly, Category="Drop", meta=(ClampMin="0.0", ClampMax="1.0"))
	float BombDropChance = 0.5f;

	UPROPERTY(EditDefaultsOnly, Category="Drop")
	bool bDropOnlyOneItem = true;

	UPROPERTY(VisibleAnywhere, Category="Drop")
	bool bDroppedItem = false;

void TryDropOnDeath();

private:
    float NetSendAccum = 0.f;
    static constexpr float NetSendInterval = 0.1f;

    void BroadcastAnimState(uint8 State);

UPROPERTY(VisibleAnywhere)
    class ABomb* HeldBomb;

void MoveForward(float AxisValue);
void StartSprint();
void StopSprint();
void MoveSide(float AxisValue);
void LookUpRate(float AxisValue);

void GunMode();
void EquipBat();
void EquipHockey();
void EquipWeapon(TSubclassOf<AMeleeWeapon> NewWeaponClass);

UFUNCTION()
void EnterRagdoll();

UFUNCTION()
void ExitRagdoll();

float PrevStamina01 = -1.f;

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

	UPROPERTY(EditAnywhere)
	float ForwardInput = 10;

	UPROPERTY(EditAnywhere)
	float RightInput= 10;

	UPROPERTY(EditAnywhere)
	float MoveForce= 20000;

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