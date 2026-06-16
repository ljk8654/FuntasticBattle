#include "LoginWidget.h"
#include "FBNetworkSubsystem.h"

#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

#include "InputCoreTypes.h"
#include "Input/Reply.h"

void ULoginWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // UI Only 상태에서 키 입력을 받기 위해 위젯에 포커스 설정
    SetIsFocusable(true);
    SetKeyboardFocus();

    if (LoginButton)
    {
        LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnLoginClicked);
    }

    if (IDInput)
    {
        IDInput->SetHintText(FText::FromString(TEXT("닉네임")));
        IDInput->OnTextChanged.AddDynamic(this, &ULoginWidget::OnTextChanged);
    }

    if (PasswordInput)
    {
        PasswordInput->SetHintText(FText::FromString(TEXT("서버 IP (예: 192.168.0.1)")));
        PasswordInput->OnTextChanged.AddDynamic(this, &ULoginWidget::OnTextChanged);
    }

    // 로그인 결과 수신 바인딩
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        Net->OnLoginResult.AddDynamic(this, &ULoginWidget::OnLoginResult);
    }
}

FReply ULoginWidget::NativeOnKeyDown(
    const FGeometry& InGeometry,
    const FKeyEvent& InKeyEvent
)
{
    if (InKeyEvent.GetKey() == EKeys::Escape)
    {
        UKismetSystemLibrary::QuitGame(
            GetWorld(),
            GetOwningPlayer(),
            EQuitPreference::Quit,
            false
        );

        return FReply::Handled();
    }

    return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
}

void ULoginWidget::OnLoginClicked()
{
    FString PlayerName = IDInput ? IDInput->GetText().ToString().TrimStartAndEnd() : TEXT("Player");
    FString ServerIP   = PasswordInput ? PasswordInput->GetText().ToString().TrimStartAndEnd() : TEXT("");

    if (PlayerName.IsEmpty())
        PlayerName = TEXT("Player");

    if (ServerIP.IsEmpty())
        ServerIP = TEXT("127.0.0.1");

    if (ClickSound)
        UGameplayStatics::PlaySound2D(this, ClickSound);

    UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
    if (!Net)
        return;

    if (!Net->IsConnected())
    {
        if (!Net->Connect(ServerIP, 7777))
        {
            if (ErrorText)
                ErrorText->SetText(FText::FromString(TEXT("서버 연결 실패. IP를 확인하세요.")));
            return;
        }
    }

    Net->SendLogin(PlayerName);

    if (ErrorText)
    {
        ErrorText->SetText(FText::FromString(TEXT("로그인 중...")));
    }
}

void ULoginWidget::OnLoginResult(int64 PlayerId, bool bSuccess)
{
    if (bSuccess)
    {
        UE_LOG(LogTemp, Log, TEXT("[Login] 성공 playerId=%lld"), PlayerId);

        OnLoginSuccess.Broadcast();
        RemoveFromParent();
    }
    else
    {
        if (ErrorText)
        {
            ErrorText->SetText(FText::FromString(TEXT("로그인 실패.")));
        }
    }
}

void ULoginWidget::OnTextChanged(const FText& Text)
{
    if (!GetWorld())
    {
        return;
    }

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