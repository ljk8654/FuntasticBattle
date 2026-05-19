#include "RemotePlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

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

void ARemotePlayer::SetTargetTransform(const FVector& NewPos, float NewYaw)
{
    TargetLocation = NewPos;
    TargetYaw = NewYaw;
}
