#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.generated.h"

class UProgressBar;

UCLASS()
class SIMPLESHOOTER_API UHUDWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

public:
    // -------- HP --------
    void SetHpNormalized(float NewHp01);

    // -------- Stamina --------
    void SetStaminaNormalized(float NewStam01);

protected:
    // ===== HP Bars =====
    UPROPERTY(meta = (BindWidget))
    UProgressBar* F_HP;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* B_HP;

    // ===== Stamina Bars =====
    UPROPERTY(meta = (BindWidget))
    UProgressBar* F_Stamina;

    UPROPERTY(meta = (BindWidget))
    UProgressBar* B_Stamina;

    // ===== HP Values =====
    float HP_Target = 1.f;   // 목표 체력
    float HP_Delay  = 1.f;   // 뒤바 현재 값

    // ===== Stamina Values =====
    float Stamina_Target = 1.f;
    float Stamina_Delay  = 1.f;

    // ===== Delay Params =====
    UPROPERTY(EditAnywhere, Category="Delay")
    float DelayStartTime = 0.3f;

    UPROPERTY(EditAnywhere, Category="Delay")
    float DelaySpeed = 2.5f;

    // ===== Timers =====
    FTimerHandle HP_DelayStartHandle;
    FTimerHandle HP_DelayTickHandle;

    FTimerHandle Stamina_DelayStartHandle;
    FTimerHandle Stamina_DelayTickHandle;

    // ===== Internal =====
    void StartHpDelay();
    void TickHpDelay();

    void StartStaminaDelay();
    void TickStaminaDelay();
};