#include "RemotePlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Animation/AnimInstance.h"

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
