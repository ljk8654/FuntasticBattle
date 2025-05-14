// Fill out your copyright notice in the Description page of Project Settings.


#include "LoginWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void ULoginWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (LoginButton)
    {
        LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnLoginClicked);
    }
}

void ULoginWidget::OnLoginClicked()
{
    FString ID = IDInput->GetText().ToString();
    FString PW = PasswordInput->GetText().ToString();

    if (ID == TEXT("admin") && PW == TEXT("1234"))
    {
        OnLoginSuccess.Broadcast();
        UE_LOG(LogTemp, Log, TEXT("로그인 성공"));
    }
    else
    {
        if (ErrorText)
        {
            ErrorText->SetText(FText::FromString(TEXT("잘못된 로그인 정보입니다.")));
        }
    }
}