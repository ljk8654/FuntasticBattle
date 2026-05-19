#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FBPackets.h"
#include "RemotePlayer.generated.h"

UCLASS()
class SIMPLESHOOTER_API ARemotePlayer : public ACharacter
{
    GENERATED_BODY()

public:
    ARemotePlayer();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    void SetTargetTransform(const FVector& NewPos, float NewYaw);
    void ApplyAnimState(uint8 State);

    int64 PlayerId = 0;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Network")
    EFBAnimState CurrentAnimState = EFBAnimState::Normal;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Network")
    float InterpSpeed = 15.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    UAnimMontage* AttackMontage = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    UAnimMontage* HitMontage = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    UAnimMontage* JumpMontage = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    UAnimMontage* StunMontage = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    UAnimMontage* RecoverMontage = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
    UAnimMontage* DeadMontage = nullptr;

private:
    FVector  TargetLocation;
    float    TargetYaw = 0.f;
};
