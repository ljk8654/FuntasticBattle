#include "WaitingRoomWidget.h"
#include "ShoorterCharater.h"
#include "FBNetworkSubsystem.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UWaitingRoomWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UWaitingRoomWidget::OnStartGameClicked);
        StartGameButton->SetVisibility(ESlateVisibility::Collapsed);
    }

    if (ColorButton)
    {
        ColorButton->OnClicked.AddDynamic(this, &UWaitingRoomWidget::OnButtonClicked);
    }

    if (ColorButton2)
    {
        ColorButton2->OnClicked.AddDynamic(this, &UWaitingRoomWidget::OnButton2Clicked);
    }

    if (ColorButton3)
    {
        ColorButton3->OnClicked.AddDynamic(this, &UWaitingRoomWidget::OnButton3Clicked);
    }

    if (ColorButton4)
    {
        ColorButton4->OnClicked.AddDynamic(this, &UWaitingRoomWidget::OnButton4Clicked);
    }
    UpdateCharacterPreviewColor(SelectedColorIndex);
}

void UWaitingRoomWidget::SetOwnerMode(bool bOwner)
{
    if (StartGameButton)
    {
        StartGameButton->SetVisibility(bOwner ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
    }
}

void UWaitingRoomWidget::OnStartGameClicked()
{
    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
}

void UWaitingRoomWidget::OnButtonClicked()
{
    SelectColor(0);
}

void UWaitingRoomWidget::OnButton2Clicked()
{
    SelectColor(1);
}

void UWaitingRoomWidget::OnButton3Clicked()
{
    SelectColor(2);
}

void UWaitingRoomWidget::OnButton4Clicked()
{
    SelectColor(3);
}

void UWaitingRoomWidget::SelectColor(int32 ColorIndex)
{
    SelectedColorIndex = ColorIndex;

    UpdateCharacterPreviewColor(ColorIndex);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
    AShoorterCharater* PlayerCharacter = Cast<AShoorterCharater>(PlayerPawn);

    if (PlayerCharacter)
    {
        if (Net->IsConnected())
            Net->SendStartGame();
        PlayerCharacter->SetOutfitMaterial(ColorIndex);
    }
}

void UWaitingRoomWidget::UpdateCharacterPreviewColor(int32 ColorIndex)
{
    if (!CharacterPreview)
    {
        return;
    }

    FLinearColor PreviewColor = FLinearColor::White;

    switch (ColorIndex)
    {
    case 0:
        PreviewColor = FLinearColor(0.2f, 0.8f, 0.2f, 1.0f); // 일반
        break;

    case 1:
        PreviewColor = FLinearColor(0.1f, 0.4f, 1.0f, 1.0f); // 희귀
        break;

    case 2:
        PreviewColor = FLinearColor(0.6f, 0.1f, 1.0f, 1.0f); // 유니크
        break;

    case 3:
        PreviewColor = FLinearColor(1.0f, 0.75f, 0.1f, 1.0f); // 전설
        break;

    default:
        PreviewColor = FLinearColor::White;
        break;
    }

    CharacterPreview->SetColorAndOpacity(PreviewColor);
}