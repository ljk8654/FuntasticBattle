#include "HUDWidget.h"
#include "Components/ProgressBar.h"
#include "TimerManager.h"

void UHUDWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // ---- 초기값 (중요) ----
    HP_Target = 1.f;
    HP_Delay  = 1.f;

    Stamina_Target = 1.f;
    Stamina_Delay  = 1.f;

    if (F_HP)       F_HP->SetPercent(1.f);
    if (B_HP)       B_HP->SetPercent(1.f);
    if (F_Stamina)  F_Stamina->SetPercent(1.f);
    if (B_Stamina)  B_Stamina->SetPercent(1.f);
}

/* =========================
        HP
========================= */

void UHUDWidget::SetHpNormalized(float NewHp01)
{
    const float NewTarget = FMath::Clamp(NewHp01, 0.f, 1.f);

    // 앞줄 즉시
    HP_Target = NewTarget;
    if (F_HP) F_HP->SetPercent(HP_Target);

    if (!GetWorld()) return;
    auto& TM = GetWorld()->GetTimerManager();

    TM.ClearTimer(HP_DelayStartHandle);
    TM.ClearTimer(HP_DelayTickHandle);

    // ✅ "감소"일 때만 딜레이
    if (HP_Target < HP_Delay)
    {
        TM.SetTimer(
            HP_DelayStartHandle,
            this,
            &UHUDWidget::StartHpDelay,
            DelayStartTime,
            false
        );
    }
    else
    {
        // 회복/같은 값 → 즉시 맞춤
        HP_Delay = HP_Target;
        if (B_HP) B_HP->SetPercent(HP_Delay);
    }
}

void UHUDWidget::StartHpDelay()
{
    if (!GetWorld()) return;

    GetWorld()->GetTimerManager().SetTimer(
        HP_DelayTickHandle,
        this,
        &UHUDWidget::TickHpDelay,
        0.016f,
        true
    );
}

void UHUDWidget::TickHpDelay()
{
    const float Dt = 0.016f;

    if (HP_Delay > HP_Target)
    {
        HP_Delay = FMath::FInterpTo(HP_Delay, HP_Target, Dt, DelaySpeed);
        if (B_HP) B_HP->SetPercent(HP_Delay);

        if (FMath::IsNearlyEqual(HP_Delay, HP_Target, 0.001f))
        {
            HP_Delay = HP_Target;
            if (B_HP) B_HP->SetPercent(HP_Delay);
            GetWorld()->GetTimerManager().ClearTimer(HP_DelayTickHandle);
        }
    }
    else
    {
        GetWorld()->GetTimerManager().ClearTimer(HP_DelayTickHandle);
    }
}

/* =========================
        STAMINA
========================= */

void UHUDWidget::SetStaminaNormalized(float NewStam01)
{
    const float NewTarget = FMath::Clamp(NewStam01, 0.f, 1.f);

    // 앞줄 즉시
    Stamina_Target = NewTarget;
    if (F_Stamina) F_Stamina->SetPercent(Stamina_Target);

    if (!GetWorld()) return;
    auto& TM = GetWorld()->GetTimerManager();

    TM.ClearTimer(Stamina_DelayStartHandle);
    TM.ClearTimer(Stamina_DelayTickHandle);

    // ✅ 감소(소모)만 딜레이
    if (Stamina_Target < Stamina_Delay)
    {
        TM.SetTimer(
            Stamina_DelayStartHandle,
            this,
            &UHUDWidget::StartStaminaDelay,
            DelayStartTime,
            false
        );
    }
    else
    {
        // 증가/같은 값 → 즉시 맞춤
        Stamina_Delay = Stamina_Target;
        if (B_Stamina) B_Stamina->SetPercent(Stamina_Delay);
    }
}

void UHUDWidget::StartStaminaDelay()
{
    if (!GetWorld()) return;

    GetWorld()->GetTimerManager().SetTimer(
        Stamina_DelayTickHandle,
        this,
        &UHUDWidget::TickStaminaDelay,
        0.016f,
        true
    );
}

void UHUDWidget::TickStaminaDelay()
{
    const float Dt = 0.016f;

    if (Stamina_Delay > Stamina_Target)
    {
        Stamina_Delay = FMath::FInterpTo(Stamina_Delay, Stamina_Target, Dt, DelaySpeed);
        if (B_Stamina) B_Stamina->SetPercent(Stamina_Delay);

        if (FMath::IsNearlyEqual(Stamina_Delay, Stamina_Target, 0.001f))
        {
            Stamina_Delay = Stamina_Target;
            if (B_Stamina) B_Stamina->SetPercent(Stamina_Delay);
            GetWorld()->GetTimerManager().ClearTimer(Stamina_DelayTickHandle);
        }
    }
    else
    {
        GetWorld()->GetTimerManager().ClearTimer(Stamina_DelayTickHandle);
    }
}
