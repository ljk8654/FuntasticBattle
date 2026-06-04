#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaitingRoomWidget.generated.h"

class UButton;
class UImage;
class UVerticalBox;
class UTextBlock;

UCLASS()
class SIMPLESHOOTER_API UWaitingRoomWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable)
    void SetOwnerMode(bool bOwner);

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

    UPROPERTY(meta = (BindWidget))
    UVerticalBox* PlayerListBox;

    UPROPERTY(meta = (BindWidget))
    UImage* CharacterPreview;

    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton;

    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton2;

    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton3;

    UPROPERTY(meta = (BindWidget))
    UButton* ColorButton4;

private:
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
    void UpdateCharacterPreviewColor(int32 ColorIndex);

private:
    int32 SelectedColorIndex = 0;
};