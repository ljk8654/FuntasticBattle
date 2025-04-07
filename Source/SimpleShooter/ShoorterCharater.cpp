// Fill out your copyright notice in the Description page of Project Settings.


#include "ShoorterCharater.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameModeBase.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AShoorterCharater::AShoorterCharater()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AShoorterCharater::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth;
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
	Gun->SetOwner(this);
}

bool AShoorterCharater::IsDead() const
{
	return Health <= 0;
}

// Called every frame
void AShoorterCharater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AShoorterCharater::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount,DamageEvent,EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"),Health);

	if (IsDead()) // 죽으면 충돌 x
	{
			ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); 

	}

	return DamageToApply;
}

// Called to bind functionality to input
void AShoorterCharater::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShoorterCharater::MoveForward);
	PlayerInputComponent->BindAction(TEXT("FastMoveForward"), IE_Pressed, this, &AShoorterCharater::StartSprint);
    PlayerInputComponent->BindAction(TEXT("FastMoveForward"), IE_Released, this, &AShoorterCharater::StopSprint);
	PlayerInputComponent->BindAxis(TEXT("MoveSide"), this, &AShoorterCharater::MoveSide);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShoorterCharater::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AShoorterCharater::Shoot);
	
}

void AShoorterCharater::Shoot()
{
	Gun->PullTrigger();
}

void AShoorterCharater::MoveForward(float AxisValue)
{	

		AddMovementInput(GetActorForwardVector() * AxisValue);
	
}

void AShoorterCharater::StartSprint()
{
    GetCharacterMovement()->MaxWalkSpeed = 600.0f;  // 스프린트 속도 증가
}

void AShoorterCharater::StopSprint()
{
    GetCharacterMovement()->MaxWalkSpeed = 300.0f;  // 원래 속도로 복구
}

void AShoorterCharater::MoveSide(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AShoorterCharater::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

// void AShoorterCharater::LookUp(float AxisValue)
// {
//	AddControllerPitchInput(AxisValue);
// }
