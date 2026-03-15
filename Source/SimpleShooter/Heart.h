// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Heart.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class SIMPLESHOOTER_API AHeart : public AActor
{
	GENERATED_BODY()

public:
	AHeart();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

	UPROPERTY(EditAnywhere, Category="Heart")
	float HealAmount = 25.f;

	// 회전/부유 연출
	UPROPERTY(EditAnywhere, Category="Heart|VFX")
	float RotateSpeedDegPerSec = 120.f;

	UPROPERTY(EditAnywhere, Category="Heart|VFX")
	float FloatAmplitude = 20.f;

	UPROPERTY(EditAnywhere, Category="Heart|VFX")
	float FloatSpeed = 2.f;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	                   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	                   bool bFromSweep, const FHitResult& SweepResult);

private:
	FVector StartLocation;
	float RunningTime = 0.f;
};