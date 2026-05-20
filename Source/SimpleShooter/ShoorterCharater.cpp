// Fill out your copyright notice in the Description page of Project Settings.


#include "ShoorterCharater.h"
#include "Gun.h"
#include "testactor.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameModeBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/DamageEvents.h"
#include "MeleeWeapon.h"
#include "ShooterPlayerController.h"
#include "HUDWidget.h"
#include "Bomb.h"
#include "Heart.h"
#include "AIController.h"
#include "FBNetworkSubsystem.h"
#include "RemotePlayer.h"

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
	Stamina = MaxStamina;
	GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("WeaponSocket"));
	Gun->SetOwner(this);
	
}

void AShoorterCharater::Jump()
{
    Super::Jump();
    BroadcastAnimState((uint8)EFBAnimState::Jump);
}

void AShoorterCharater::Landed(const FHitResult& Hit)
{
    Super::Landed(Hit);
    BroadcastAnimState((uint8)EFBAnimState::Normal);
}

void AShoorterCharater::BroadcastAnimState(uint8 State)
{
    if (!IsPlayerControlled()) return;
    if (UGameInstance* GI = GetGameInstance())
        if (UFBNetworkSubsystem* Net = GI->GetSubsystem<UFBNetworkSubsystem>())
            if (Net->IsConnected())
                Net->SendAnimState(State);
}

void AShoorterCharater::EnableMovement()
{
	bIsAttacking = false;
    BroadcastAnimState((uint8)EFBAnimState::Normal);
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
	 const float Stamina01 = Stamina / MaxStamina;

    if (!FMath::IsNearlyEqual(Stamina01, PrevStamina01, 0.001f))
    {
        PrevStamina01 = Stamina01;

        if (APlayerController* PC0 = Cast<APlayerController>(GetController()))
        {
            if (AShooterPlayerController* PC = Cast<AShooterPlayerController>(PC0))
            {
                if (UHUDWidget* HUD = PC->GetHUDWidget())
                {
                    HUD->SetStaminaNormalized(Stamina01);
                }
            }
        }
    }

    // 100ms마다 서버로 위치 전송
    if (IsPlayerControlled())
    {
        NetSendAccum += DeltaTime;
        if (NetSendAccum >= NetSendInterval)
        {
            NetSendAccum = 0.f;
            if (UGameInstance* GI = GetGameInstance())
            {
                if (UFBNetworkSubsystem* Net = GI->GetSubsystem<UFBNetworkSubsystem>())
                {
                    if (Net->IsConnected())
                    {
                        FVector Pos = GetActorLocation();
                        float Yaw = GetActorRotation().Yaw;
                        FVector Vel = GetCharacterMovement()->Velocity;
                        Net->SendMove(Pos, Yaw, Vel);
                    }
                }
            }
        }
    }
}

float AShoorterCharater::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float DamageToApply = Super::TakeDamage(DamageAmount,DamageEvent,EventInstigator, DamageCauser);
	DamageToApply = FMath::Min(Health, DamageToApply);
	Health -= DamageToApply;

	if (APlayerController* PC0 = Cast<APlayerController>(GetController()))
	{
    	if (AShooterPlayerController* PC = Cast<AShooterPlayerController>(PC0))
    	{
        	if (UHUDWidget* HUD = PC->GetHUDWidget())
        	{
            	HUD->SetHpNormalized(Health / MaxHealth);
        	}
    	}
	}

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
		TryDropOnDeath();
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

		BroadcastAnimState((uint8)EFBAnimState::Dead);
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	} else 
	{
		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
        if (AnimInstance && HitMontage)
        {
			AnimInstance->Montage_Play(HitMontage);
            BroadcastAnimState((uint8)EFBAnimState::Hit);
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
	PlayerInputComponent->BindKey(EKeys::Enter, IE_Pressed, this, &AShoorterCharater::TryStartGame);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShoorterCharater::LookUpRate);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AShoorterCharater::Shoot);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AShoorterCharater::PunchAttack);
	PlayerInputComponent->BindAction(TEXT("GunMode"), EInputEvent::IE_Pressed, this, &AShoorterCharater::GunMode);
	PlayerInputComponent->BindAction(TEXT("BatMode"), EInputEvent::IE_Pressed, this, &AShoorterCharater::EquipBat);
	PlayerInputComponent->BindAction(TEXT("HockeyMode"), EInputEvent::IE_Pressed, this, &AShoorterCharater::EquipHockey);
	PlayerInputComponent->BindAction(TEXT("ThrowBomb"), IE_Pressed, this, &AShoorterCharater::ThrowBomb);
}

void AShoorterCharater::TryStartGame()
{
    AShooterPlayerController* PC = Cast<AShooterPlayerController>(GetController());
    if (!PC || !PC->IsOwnerInWaitingRoom()) return;

    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
        if (Net->IsConnected())
            Net->SendStartGame();
}

void AShoorterCharater::Shoot()
{
	if (ItemMode == 0) Gun->PullTrigger();
}



void AShoorterCharater::MoveForward(float AxisValue)
{
    if (!Controller) return;

    if (AxisValue == 0.f) return;

    const FRotator ControlRot = Controller->GetControlRotation();
    const FRotator YawRot(0.f, ControlRot.Yaw, 0.f);

    const FVector Forward = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
    AddMovementInput(Forward, AxisValue);
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
    if (!Controller) return;

    if (AxisValue == 0.f) return;
	
    const FRotator ControlRot = Controller->GetControlRotation();
    const FRotator YawRot(0.f, ControlRot.Yaw, 0.f);

    const FVector Right = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);
    AddMovementInput(Right, AxisValue);
}

void AShoorterCharater::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShoorterCharater::PunchAttack()
{
	if (bIsAttacking)
	{
    	return;
	}
	bIsAttacking = true;
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

	//DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius, Rotation, DrawColor, false, 2.f);

	if (bResult)
	{
		for (const FHitResult& Hit : HitResults)
		{
			AActor* HitActor = Hit.GetActor();
			if (!HitActor || HitActor == this || !HitActor->IsA<ACharacter>()) continue;

			if (ARemotePlayer* Remote = Cast<ARemotePlayer>(HitActor))
			{
				// 네트워크 상의 다른 플레이어 → 서버에 데미지 전송
				if (UGameInstance* GI = GetGameInstance())
					if (UFBNetworkSubsystem* Net = GI->GetSubsystem<UFBNetworkSubsystem>())
						if (Net->IsConnected())
							Net->SendDamage(Remote->PlayerId, AmountDamage);
			}
			else
			{
				// 로컬 NPC 등
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
        BroadcastAnimState((uint8)EFBAnimState::Attack);
		FTimerHandle UnfreezeHandle;
		GetWorldTimerManager().SetTimer(UnfreezeHandle, this, &AShoorterCharater::EnableMovement, 1.3f, false);
	}
}

void AShoorterCharater::BroadcastItemState(uint8 ItemType)
{
    if (!IsPlayerControlled()) return;
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
        if (Net->IsConnected())
            Net->SendItemState(ItemType);
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
    BroadcastItemState(1); // Gun
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
    BroadcastItemState(NewWeaponClass == HockeyClass ? 3 : 2); // Hockey=3, Bat=2
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

    BroadcastAnimState((uint8)EFBAnimState::Stunned);
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
    SetActorLocation(FVector(MeshLocation.X, MeshLocation.Y, MeshLocation.Z + 5.0f));

    // 메시 위치와 회전 리셋
    GetMesh()->SetRelativeLocation(FVector(0.f, 0.f, -88.f));
	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));

    // 이동 가능하도록 설정
    GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);

    // 시점 리셋 (선택)
	SetActorRotation(SavedActorRotation); // 저장된 회전으로 복구
	
    BroadcastAnimState((uint8)EFBAnimState::Recover);
    UE_LOG(LogTemp, Warning, TEXT("기상 완료 (애니메이션 없음)"));
}

// void AShoorterCharater::LookUp(float AxisValue)
// {
//	AddControllerPitchInput(AxisValue);
// }

void AShoorterCharater::PickupBomb(ABomb* Bomb)
{
    if (HeldBomb == nullptr && Bomb)
    {
        HeldBomb = Bomb;
        HeldBomb->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("BombSocket"));
        HeldBomb->SetOwner(this);
        BroadcastItemState(4); // Bomb
    }
}

void AShoorterCharater::ThrowBomb()
{
    if (HeldBomb)
    {
        FVector HandLoc = GetMesh()->GetSocketLocation(FName("BombSocket"));

        FVector SpawnLoc = HandLoc
            + GetActorForwardVector() * 70.f
            + FVector(0,0,40.f);

        HeldBomb->SetActorLocation(SpawnLoc);
        HeldBomb->SetActorRotation(GetControlRotation());
        HeldBomb->OnThrown();
        HeldBomb->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        HeldBomb = nullptr;

        // 서버에 투척 위치/방향 전송
        if (IsPlayerControlled())
            if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
                if (Net->IsConnected())
                {
                    FRotator AimRot = GetControlRotation();
                    Net->SendThrowBomb(SpawnLoc, AimRot.Yaw, AimRot.Pitch);
                    Net->SendItemState(0); // 폭탄 투척 후 아이템 없음
                }
    }
}

bool AShoorterCharater::Heal(float Amount)
{
    if (Amount <= 0.f) return false;
    if (IsDead()) return false;
    if (Health >= MaxHealth) return false; // 풀피면 실패

    Health = FMath::Clamp(Health + Amount, 0.f, MaxHealth);

    // HUD 업데이트
    if (APlayerController* PC0 = Cast<APlayerController>(GetController()))
    {
        if (AShooterPlayerController* PC = Cast<AShooterPlayerController>(PC0))
        {
            if (UHUDWidget* HUD = PC->GetHUDWidget())
            {
                HUD->SetHpNormalized(Health / MaxHealth);
            }
        }
    }

    // 50% 이상이면 기절 플래그 리셋
    if (Health > MaxHealth * 0.5f)
    {
        bHasTriggeredStun = false;
    }

    return true; // 회복 성공
}

void AShoorterCharater::TryDropOnDeath()
{
    if (!bEnableDropOnDeath) return;
    if (IsPlayerControlled()) return;
    if (bDroppedItem) return;
    bDroppedItem = true;

    const FVector BaseLoc = GetActorLocation() + FVector(0.f, 0.f, 60.f);

    // 네트워크 연결 시 서버를 통해 드롭 동기화 (중복 방지)
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        if (Net->IsConnected() && bDropOnlyOneItem)
        {
            float R = FMath::FRand();
            uint8 DropType = 0;
            if (HeartDropClass && R < HeartDropChance)
                DropType = 1;
            else if (BombDropClass && R < HeartDropChance + BombDropChance)
                DropType = 2;

            if (DropType > 0)
                Net->SendItemDrop(DropType, BaseLoc);
            return;
        }
    }

    // 오프라인(싱글플레이) 폴백: 로컬 스폰
    UWorld* World = GetWorld();
    if (!World) return;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

    if (bDropOnlyOneItem)
    {
        float R = FMath::FRand();
        if (HeartDropClass && R < HeartDropChance)
            World->SpawnActor<AHeart>(HeartDropClass, BaseLoc, FRotator::ZeroRotator, Params);
        else if (BombDropClass && R < HeartDropChance + BombDropChance)
            World->SpawnActor<ABomb>(BombDropClass, BaseLoc + FVector(20,0,10), FRotator::ZeroRotator, Params);
    }
}