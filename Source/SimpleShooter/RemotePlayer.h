#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FBPackets.h"
#include "RemotePlayer.generated.h"

class AGun;
class AMeleeWeapon;
class ABomb;

UCLASS()
class SIMPLESHOOTER_API ARemotePlayer : public ACharacter
{
    GENERATED_BODY()

public:
    ARemotePlayer();

    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    void SetTargetTransform(const FVector& NewPos, float NewYaw, const FVector& NewVel = FVector::ZeroVector);
    void ApplyAnimState(uint8 State);
    void SetItemState(uint8 ItemType);
    void SpawnSyncBomb(FVector Pos, float Yaw, float Pitch);

    int64 PlayerId = 0;

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

    // 원격 플레이어 무기 BP 클래스 (BP_RemotePlayer에서 지정)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
    TSubclassOf<AGun> GunClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
    TSubclassOf<AMeleeWeapon> BatClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
    TSubclassOf<AMeleeWeapon> HockeyClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Weapon")
    TSubclassOf<ABomb> BombClass;

private:
    FVector  TargetLocation;
    float    TargetYaw = 0.f;

    UPROPERTY()
    AGun* CurrentGun = nullptr;

    UPROPERTY()
    AMeleeWeapon* CurrentMeleeWeapon = nullptr;

    UPROPERTY()
    ABomb* CurrentBomb = nullptr;
};
