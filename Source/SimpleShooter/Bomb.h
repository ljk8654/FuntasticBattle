// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundAttenuation.h"
#include "Bomb.generated.h"

UCLASS()
class SIMPLESHOOTER_API ABomb : public AActor
{
    GENERATED_BODY()
    
public:
    ABomb();
    // 퓨즈 소리
    UPROPERTY(EditAnywhere, Category="Sound")
    USoundBase* FuseSound;

    // 폭발 소리
    UPROPERTY(EditAnywhere, Category="Sound")
    USoundBase* ExplosionSound;

    UPROPERTY(EditAnywhere, Category="Sound")
    USoundAttenuation* FuseAttenuation;

    UPROPERTY(EditAnywhere, Category="Sound")
    USoundAttenuation* ExplosionAttenuation;

    // 폭탄 퓨즈 타이머 제어
    void StartFuse();
    void StopFuse();

    // 플레이어가 주움/던짐 시 (연동용)
    void OnPickedUp();
    void OnThrown();

    // 원격 클라이언트 시각 동기화 전용 폭탄으로 설정 (데미지 없음)
    void SetAsSyncBomb();

protected:
    virtual void BeginPlay() override;
    void Explode();

    // 플레이어가 가까이 오면 습득
    UFUNCTION()
    void OnPickupOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
    // 컴포넌트들
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

    UPROPERTY(VisibleAnywhere)
    class USphereComponent* PickupSphere;

    UPROPERTY(VisibleAnywhere)
    class UProjectileMovementComponent* ProjectileMovement;

    UPROPERTY(VisibleAnywhere)
    class UNiagaraComponent* TrailEffect;

    UPROPERTY(EditAnywhere)
    class UNiagaraSystem* ExplosionEffect;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ExplosionDamage = 40.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float ExplosionRadius = 300.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FuseTime = 3.0f;


private:
    FTimerHandle ExplosionTimerHandle;
    bool bFuseStarted = false;
    bool bIsSyncBomb  = false;

    UPROPERTY()
    UAudioComponent* FuseAudioComponent;
};