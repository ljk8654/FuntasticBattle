#include "LoginWidget.h"
#include "FBNetworkSubsystem.h"
#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void ULoginWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (LoginButton)
        LoginButton->OnClicked.AddDynamic(this, &ULoginWidget::OnLoginClicked);

    if (IDInput)
        IDInput->OnTextChanged.AddDynamic(this, &ULoginWidget::OnTextChanged);

    if (PasswordInput)
        PasswordInput->OnTextChanged.AddDynamic(this, &ULoginWidget::OnTextChanged);

    // 로그인 결과 수신 바인딩
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
        Net->OnLoginResult.AddDynamic(this, &ULoginWidget::OnLoginResult);
}

void ULoginWidget::OnLoginClicked()
{
    FString PlayerName = IDInput ? IDInput->GetText().ToString() : TEXT("Player");
    if (PlayerName.IsEmpty()) PlayerName = TEXT("Player");

    if (ClickSound)
        UGameplayStatics::PlaySound2D(this, ClickSound);

    UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>();
    if (!Net) return;

    // 서버에 연결 (이미 연결돼 있으면 무시)
    if (!Net->IsConnected())
    {
        if (!Net->Connect(TEXT("127.0.0.1"), 7777))
        {
            if (ErrorText)
                ErrorText->SetText(FText::FromString(TEXT("서버 연결 실패. 서버가 실행 중인지 확인하세요.")));
            return;
        }
    }

    Net->SendLogin(PlayerName);

    if (ErrorText)
        ErrorText->SetText(FText::FromString(TEXT("로그인 중...")));
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
            ErrorText->SetText(FText::FromString(TEXT("로그인 실패.")));
    }
}

void ULoginWidget::OnTextChanged(const FText& Text)
{
    float Now = GetWorld()->GetTimeSeconds();
    if (Now - LastInputSoundTime >= InputInterval)
    {
        if (InputSound)
            UGameplayStatics::PlaySound2D(this, InputSound);
        LastInputSoundTime = Now;
    }
}
