// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void ULoginWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (LoginButton)
    {
        LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnLoginClicked);
    }

    // ID 입력 소리
    if (IDInput)
    {
        IDInput->OnTextChanged.AddDynamic(
            this,
            &ULoginWidget::OnTextChanged
        );
    }

    // PW 입력 소리
    if (PasswordInput)
    {
        PasswordInput->OnTextChanged.AddDynamic(
            this,
            &ULoginWidget::OnTextChanged
        );
    }
}

void ULoginWidget::OnLoginClicked()
{
    FString ID = IDInput->GetText().ToString();
    FString PW = PasswordInput->GetText().ToString();

    if (ClickSound)
    {
        UGameplayStatics::PlaySound2D(this, ClickSound);
    }

    if (ID == TEXT("admin") && PW == TEXT("1234"))
    {
        OnLoginSuccess.Broadcast();
        UE_LOG(LogTemp, Log, TEXT("로그인 성공"));
       RemoveFromParent();
    }
    else
    {
        if (ErrorText)
        {
            ErrorText->SetText(FText::FromString(TEXT("잘못된 로그인 정보입니다.")));
        }
    }
}

void ULoginWidget::OnTextChanged(const FText& Text)
{
    float Now = GetWorld()->GetTimeSeconds();

    if (Now - LastInputSoundTime >= InputInterval)
    {
        if (InputSound)
        {
            UGameplayStatics::PlaySound2D(this, InputSound);
        }
        LastInputSoundTime = Now;
    }
}