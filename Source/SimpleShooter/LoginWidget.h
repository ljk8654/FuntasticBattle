// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoginWidget.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLoginSuccess);

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API ULoginWidget : public UUserWidget
{
	GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    FOnLoginSuccess OnLoginSuccess;

protected:
    UPROPERTY(meta = (BindWidget))
    class UEditableTextBox* IDInput;

    UPROPERTY(meta = (BindWidget))
    class UEditableTextBox* PasswordInput;

    UPROPERTY(meta = (BindWidget))
    class UButton* LoginButton;

    UPROPERTY(meta = (BindWidget))
    class UTextBlock* ErrorText;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound")
    USoundBase* ClickSound;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound")
    USoundBase* InputSound;

    
private:
    UFUNCTION()
    void OnLoginClicked();
    UFUNCTION()
    void OnTextChanged(const FText& Text);
    UFUNCTION()
    void OnLoginResult(int64 PlayerId, bool bSuccess);

    float LastInputSoundTime = 0.f;
    float InputInterval = 0.0f;
};
