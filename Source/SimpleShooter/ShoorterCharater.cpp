// Fill out your copyright notice in the Description page of Project Settings.


#include "ShoorterCharater.h"
#include "Gun.h"
#include "testactor.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameModeBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/DamageEvents.h"
#include "MeleeWeapon.h"

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
	AmountDamage = PlayerDamage;
	AmountStunDamage = PlayerStunDamage;
	AmountForce = PlayerForce;
	Health = MaxHealth;
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
	Gun->SetOwner(this);
	
}

void AShoorterCharater::EnableMovement()
{
	GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}

bool AShoorterCharater::IsDead() const
{
	return Health <= 0;
}

float AShoorterCharater::HealthPercent() const
{
	return Health / MaxHealth;
}

float AShoorterCharater::StaminaPercent() const
{
	return Stamina / MaxStamina;
}

// Called every frame
void AShoorterCharater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (running)
	{
		Stamina -= 0.1f; // 스프린트 시 스태미너 감소
		if (Stamina <= 0.0f) // 스태미너가 0이 되면 스프린트 중지
		{
			GetCharacterMovement()->MaxWalkSpeed = 300.0f; // 원래 속도로 복구
		}
		else if (Stamina > MaxStamina) // 스태미너가 최대치를 초과하지 않도록 제한
		{
			Stamina = MaxStamina;
		}
	}
	else 
	{
		if (Stamina < MaxStamina){
		Stamina += 0.05f; // 스태미너 증가
		}
	}
}

float AShoorterCharater::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount,DamageEvent,EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;

    // 체력이 50% 이하로 떨어졌고 아직 기절 안 했으면 기절 처리
    if (!bIsRagdoll && !bHasTriggeredStun && Health <= MaxHealth * 0.5f && Health > 0.f)
    {
        EnterRagdoll();
        bHasTriggeredStun = true;
    }

    // 체력이 다시 50% 이상으로 회복되면 기절 체크 플래그 초기화
    if (Health > MaxHealth * 0.5f)
    {
        bHasTriggeredStun = false;
    }

	if (IsDead())
	{
			ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		// 죽음 애니메이션 물리 시뮬 적용
		FVector AttackerLocation;
		if(EventInstigator && EventInstigator->GetPawn())
		{
    	AttackerLocation = EventInstigator->GetPawn()->GetActorLocation();
		}
		else if (DamageCauser)
		{
    	AttackerLocation = DamageCauser->GetActorLocation();
		}
		else
		{
    	AttackerLocation = FVector::ZeroVector; // 예외처리
	}// 공격자 위치
		FVector VictimLocation = GetActorLocation(); // 피격자(자기 자신) 위치

		// 넉백 방향 = 피격자에서 공격자를 향하는 방향의 반대
		FVector KnockbackDirection = (VictimLocation - AttackerLocation).GetSafeNormal();
		GetMesh()->SetSimulatePhysics(true);
		GetCharacterMovement()->DisableMovement();;
		GetMesh()->AddImpulse(KnockbackDirection * AmountForce, NAME_None, true);

		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); 

	} else 
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        if (AnimInstance && HitMontage)
        {
			// 피격 애니메이션
            AnimInstance->Montage_Play(HitMontage);
			GetCharacterMovement()->DisableMovement();

			// 일정 시간 후 이동 가능하게 복구
			FTimerHandle UnfreezeHandle;
			GetWorldTimerManager().SetTimer(UnfreezeHandle, this, &AShoorterCharater::EnableMovement, 0.7f, false);
			UE_LOG(LogTemp, Warning, TEXT("Health left %f"),Health);
        }
		
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
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AShoorterCharater::Jump);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShoorterCharater::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AShoorterCharater::Shoot);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AShoorterCharater::PunchAttack);
	PlayerInputComponent->BindAction(TEXT("GunMode"), EInputEvent::IE_Pressed, this, &AShoorterCharater::GunMode);
	PlayerInputComponent->BindAction(TEXT("BatMode"), EInputEvent::IE_Pressed, this, &AShoorterCharater::EquipBat);
	PlayerInputComponent->BindAction(TEXT("HockeyMode"), EInputEvent::IE_Pressed, this, &AShoorterCharater::EquipHockey);
}

void AShoorterCharater::Shoot()
{
	if (ItemMode == 0) Gun->PullTrigger();
}



void AShoorterCharater::MoveForward(float AxisValue)
{	

	AddMovementInput(GetActorForwardVector() * AxisValue);
	
}

void AShoorterCharater::StartSprint()
{
	running = true;
    GetCharacterMovement()->MaxWalkSpeed = 600.0f;  // 스프린트 속도 증가
}

void AShoorterCharater::StopSprint()
{
	running = false;
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

void AShoorterCharater::PunchAttack()
{
	TArray<FHitResult> HitResults;
	FCollisionQueryParams Params(NAME_None, false, this);

	float AttackRange = 100.f;
	float AttackRadius = 15.f;

	FVector Start = GetActorLocation();
	FVector End = Start + GetActorForwardVector() * AttackRange;

	bool bResult = GetWorld()->SweepMultiByChannel(
		OUT HitResults,
		Start,
		End,
		FQuat::Identity,
		ECollisionChannel::ECC_EngineTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius),
		Params
	);

	// 디버그용 캡슐
	FVector Vec = GetActorForwardVector() * AttackRange;
	FVector Center = GetActorLocation() + Vec * 0.5f;
	float HalfHeight = AttackRange * 0.5f + AttackRadius;
	FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
	FColor DrawColor = bResult ? FColor::Green : FColor::Red;

	DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius, Rotation, DrawColor, false, 2.f);

	if (bResult)
	{
		for (const FHitResult& Hit : HitResults)
		{
			AActor* HitActor = Hit.GetActor();
			if (HitActor && HitActor != this && HitActor->IsA<ACharacter>())
			{
				FDamageEvent DamageEvent;
				HitActor->TakeDamage(AmountDamage, DamageEvent, GetController(), this);
			}
		}
		UE_LOG(LogTemp, Warning, TEXT("Sweep hit %d actors"), HitResults.Num());
		for (auto& Hit : HitResults)
		{
    		if (Hit.GetActor())
    		{
        	UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *Hit.GetActor()->GetName());
    		}
		}
	}

	// 애니메이션 재생 및 이동 제어
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && AttackMontage)
	{
		AnimInstance->Montage_Play(AttackMontage);
		GetCharacterMovement()->DisableMovement();

		FTimerHandle UnfreezeHandle;
		GetWorldTimerManager().SetTimer(UnfreezeHandle, this, &AShoorterCharater::EnableMovement, 0.7f, false);
	}
}

void AShoorterCharater::GunMode()
{
	ItemMode = 0;
	if (Bat)
    {
        Bat->Destroy();
        Bat = nullptr;
    }

    if (Gun == nullptr)
    {
        Gun = GetWorld()->SpawnActor<AGun>(GunClass);
        GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
        Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
        Gun->SetOwner(this);
    }
}

void AShoorterCharater::EquipBat()
{
	EquipWeapon(BatClass);
}

void AShoorterCharater::EquipHockey()
{
	EquipWeapon(HockeyClass);
}

void AShoorterCharater::EquipWeapon(TSubclassOf<AMeleeWeapon> NewWeaponClass)
{
    if (MeleeWeapon)
    {
        MeleeWeapon->Destroy();
        MeleeWeapon = nullptr;
    }

    MeleeWeapon = GetWorld()->SpawnActor<AMeleeWeapon>(NewWeaponClass);
    if (MeleeWeapon)
    {
		GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
		if (NewWeaponClass == HockeyClass)	{
			MeleeWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("HockeySocket"));
		}
        else {
			MeleeWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
		}
        AmountDamage = PlayerDamage + MeleeWeapon->Damage;
        AmountStunDamage = PlayerStunDamage + MeleeWeapon->StunDamage;
        AmountForce = PlayerForce + MeleeWeapon->AddForce;
    }
}

void AShoorterCharater::EnterRagdoll()
{
	bIsRagdoll = true;
	SavedActorRotation = GetActorRotation(); // 기절 시 회전 저장

    GetMesh()->SetSimulatePhysics(true);
    GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
    GetCharacterMovement()->DisableMovement();

    // 캡슐 비활성화
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    // 일정 시간 후 기상
    FTimerHandle RagdollTimerHandle;
    GetWorldTimerManager().SetTimer(RagdollTimerHandle, this, &AShoorterCharater::ExitRagdoll, RagdollRecoverTime, false);

    UE_LOG(LogTemp, Warning, TEXT(">> 기절 상태 진입 (Ragdoll)"));
}

void AShoorterCharater::ExitRagdoll()
{
    bIsRagdoll = false;

    // 물리 OFF + 충돌 설정 복구
    GetMesh()->SetSimulatePhysics(false);
    GetMesh()->SetCollisionProfileName(TEXT("CharacterMesh"));

    // 캡슐 활성화
    GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

    // 캡슐 위치 보정 (바닥에 깔린 메시 → 정상 높이로 이동)
    FVector MeshLocation = GetMesh()->GetComponentLocation();
    SetActorLocation(FVector(MeshLocation.X, MeshLocation.Y, MeshLocation.Z + 88.f));

    // 메시 위치와 회전 리셋
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

    // 이동 가능하도록 설정
    GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);

    // 시점 리셋 (선택)
	SetActorRotation(SavedActorRotation); // 저장된 회전으로 복구
	
    UE_LOG(LogTemp, Warning, TEXT("기상 완료 (애니메이션 없음)"));
}

// void AShoorterCharater::LookUp(float AxisValue)
// {
//	AddControllerPitchInput(AxisValue);
// }
