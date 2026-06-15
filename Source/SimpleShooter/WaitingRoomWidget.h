#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaitingRoomWidget.generated.h"

class UButton;
class UImage;

UCLASS()
class SIMPLESHOOTER_API UWaitingRoomWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    void SetOwnerMode(bool bOwner);

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* CharacterButton1;

    UPROPERTY(meta = (BindWidget))
    UButton* CharacterButton2;

    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton2;

    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton3;

    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton4;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character")
    int32 SelectedColorIndex = 0;

    UFUNCTION()
    void OnStartGameClicked();

    UFUNCTION()
    void OnButtonClicked();

    UFUNCTION()
    void OnButton2Clicked();

    UFUNCTION()
    void OnButton3Clicked();

    UFUNCTION()
    void OnButton4Clicked();

    void SelectColor(int32 ColorIndex);

    void SetUIMode();

    void UpdateCharacterPreviewColor(int32 ColorIndex);
    
    UFUNCTION()
    void OnCharacterButton1Clicked();

    UFUNCTION()
    void OnCharacterButton2Clicked();
};