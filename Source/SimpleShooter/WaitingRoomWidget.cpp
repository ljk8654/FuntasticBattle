#include "WaitingRoomWidget.h"
#include "FBNetworkSubsystem.h"
#include "Components/Button.h"

void UWaitingRoomWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UWaitingRoomWidget::OnStartGameClicked);
        StartGameButton->SetVisibility(ESlateVisibility::Collapsed);
    }
}

void UWaitingRoomWidget::SetOwnerMode(bool bOwner)
{
    if (StartGameButton)
        StartGameButton->SetVisibility(bOwner ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void UWaitingRoomWidget::OnStartGameClicked()
{
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        if (Net->IsConnected())
            Net->SendStartGame();
    }
}
