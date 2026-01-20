#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"


#include "HUDWidget.h"
#include "LoomList.h"
#include "LoginWidget.h"

#include "ShooterPlayerController.generated.h"

UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

    UPROPERTY(EditAnywhere, Category="UI")
    TSubclassOf<UHUDWidget> HUDClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
    TSubclassOf<ULoginWidget> LoginWidgetClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
    TSubclassOf<ULoomList> RoomListClass;

    UPROPERTY()
    ULoginWidget* CurrentLoginWidget;

    UFUNCTION()
    void OnLoginSuccess();

    UFUNCTION()
    void OnEnterRoomSuccess();

	UHUDWidget* GetHUDWidget() const { return HUD; }
protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<class UUserWidget> WinnerScreenClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class UUserWidget> LoseScreenClass;

    UPROPERTY(EditAnywhere)
    float RestartDelay = 5.f;

    FTimerHandle RestartTimer;

    UPROPERTY()
    UHUDWidget* HUD;

    UPROPERTY()
    ULoomList* RoomList;
};
