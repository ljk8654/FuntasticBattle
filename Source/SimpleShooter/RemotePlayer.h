#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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

    int64 PlayerId = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Network")
    float InterpSpeed = 15.f;

private:
    FVector  TargetLocation;
    float    TargetYaw = 0.f;
};
