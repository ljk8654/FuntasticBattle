#include "RemotePlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimInstance.h"
#include "Gun.h"
#include "MeleeWeapon.h"
#include "Bomb.h"
#include "Kismet/GameplayStatics.h"

ARemotePlayer::ARemotePlayer()
{
    PrimaryActorTick.bCanEverTick = true;
    SetCanBeDamaged(false);
}

void ARemotePlayer::BeginPlay()
{
    Super::BeginPlay();

    TargetLocation = GetActorLocation();
    TargetYaw = GetActorRotation().Yaw;

    // 입력 및 이동 비활성화
    GetCharacterMovement()->DisableMovement();
    GetCharacterMovement()->GravityScale = 0.f;
    GetCapsuleComponent()->SetCollisionProfileName(TEXT("OverlapAll"));
}

void ARemotePlayer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector CurrentLoc = GetActorLocation();
    FVector NewLoc = FMath::VInterpTo(CurrentLoc, TargetLocation, DeltaTime, InterpSpeed);
    SetActorLocation(NewLoc, false, nullptr, ETeleportType::TeleportPhysics);

    float CurrentYaw = GetActorRotation().Yaw;
    float NewYaw = FMath::FInterpTo(CurrentYaw, TargetYaw, DeltaTime, InterpSpeed);
    SetActorRotation(FRotator(0.f, NewYaw, 0.f));
}

void ARemotePlayer::SetTargetTransform(const FVector& NewPos, float NewYaw, const FVector& NewVel)
{
    TargetLocation = NewPos;
    TargetYaw = NewYaw;
    // CharacterMovement가 비활성화되어 있어도 Velocity는 AnimBP가 읽을 수 있음
    GetCharacterMovement()->Velocity = NewVel;
}

void ARemotePlayer::ApplyAnimState(uint8 State)
{
    CurrentAnimState = static_cast<EFBAnimState>(State);

    UAnimInstance* AnimInst = GetMesh() ? GetMesh()->GetAnimInstance() : nullptr;
    if (!AnimInst) return;

    UAnimMontage* Montage = nullptr;
    switch (CurrentAnimState)
    {
    case EFBAnimState::Attack:  Montage = AttackMontage;  break;
    case EFBAnimState::Hit:     Montage = HitMontage;     break;
    case EFBAnimState::Stunned: Montage = StunMontage;    break;
    case EFBAnimState::Recover: Montage = RecoverMontage; break;
    case EFBAnimState::Dead:    Montage = DeadMontage;    break;
    default: break;
    }

    if (Montage)
        AnimInst->Montage_Play(Montage);
}

void ARemotePlayer::SetItemState(uint8 ItemType)
{
    if (CurrentGun)        { CurrentGun->Destroy();        CurrentGun = nullptr; }
    if (CurrentMeleeWeapon){ CurrentMeleeWeapon->Destroy(); CurrentMeleeWeapon = nullptr; }
    if (CurrentBomb)       { CurrentBomb->Destroy();        CurrentBomb = nullptr; }

    EFBItemType Item = static_cast<EFBItemType>(ItemType);
    switch (Item)
    {
    case EFBItemType::Gun:
        if (GunClass)
        {
            CurrentGun = GetWorld()->SpawnActor<AGun>(GunClass);
            if (CurrentGun)
            {
                CurrentGun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
                CurrentGun->SetOwner(this);
            }
        }
        break;
    case EFBItemType::Bat:
        if (BatClass)
        {
            CurrentMeleeWeapon = GetWorld()->SpawnActor<AMeleeWeapon>(BatClass);
            if (CurrentMeleeWeapon)
            {
                CurrentMeleeWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
                CurrentMeleeWeapon->SetOwner(this);
            }
        }
        break;
    case EFBItemType::Hockey:
        if (HockeyClass)
        {
            CurrentMeleeWeapon = GetWorld()->SpawnActor<AMeleeWeapon>(HockeyClass);
            if (CurrentMeleeWeapon)
            {
                CurrentMeleeWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("HockeySocket"));
                CurrentMeleeWeapon->SetOwner(this);
            }
        }
        break;
    case EFBItemType::Bomb:
        {
            // 새 폭탄 스폰 없이 레벨에 있는 가장 가까운 폭탄을 찾아 부착
            // (새 폭탄을 스폰하면 원래 폭탄과 겹쳐 두 개로 보이는 문제 발생)
            TArray<AActor*> BombActors;
            UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABomb::StaticClass(), BombActors);
            float MinDist = FLT_MAX;
            ABomb* ClosestBomb = nullptr;
            for (AActor* Actor : BombActors)
            {
                ABomb* B = Cast<ABomb>(Actor);
                if (B && !B->IsHidden())
                {
                    float Dist = FVector::Dist(B->GetActorLocation(), GetActorLocation());
                    if (Dist < MinDist) { MinDist = Dist; ClosestBomb = B; }
                }
            }
            if (ClosestBomb)
            {
                CurrentBomb = ClosestBomb;
                CurrentBomb->SetAsSyncBomb();
                CurrentBomb->OnPickedUp();
                CurrentBomb->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("BombSocket"));
                CurrentBomb->SetOwner(this);
            }
        }
        break;
    case EFBItemType::None:
    default:
        break;
    }
}

void ARemotePlayer::SpawnSyncBomb(FVector Pos, float Yaw, float Pitch)
{
    // 손에 들고 있던 폭탄 분리 후 제거
    if (CurrentBomb)
    {
        CurrentBomb->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
        CurrentBomb->Destroy();
        CurrentBomb = nullptr;
    }

    if (!BombClass) return;

    ABomb* SyncBomb = GetWorld()->SpawnActor<ABomb>(BombClass, Pos, FRotator(Pitch, Yaw, 0.f));
    if (SyncBomb)
    {
        SyncBomb->SetAsSyncBomb();
        SyncBomb->OnThrown();
    }
}
