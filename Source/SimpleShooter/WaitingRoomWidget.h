#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaitingRoomWidget.generated.h"

class UButton;

UCLASS()
class SIMPLESHOOTER_API UWaitingRoomWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    void SetOwnerMode(bool bOwner);

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

private:
    UFUNCTION()
    void OnStartGameClicked();
};
