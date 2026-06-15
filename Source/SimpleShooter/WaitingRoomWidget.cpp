#include "WaitingRoomWidget.h"

#include "ShoorterCharater.h"
#include "FBNetworkSubsystem.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

void UWaitingRoomWidget::NativeConstruct()
{
    Super::NativeConstruct();
    if (CharacterButton1)
    {
    CharacterButton1->OnClicked.AddDynamic(
        this,
        &UWaitingRoomWidget::OnCharacterButton1Clicked
    );
    }

    if (CharacterButton2)
    {
    CharacterButton2->OnClicked.AddDynamic(
        this,
        &UWaitingRoomWidget::OnCharacterButton2Clicked
    );
    }

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

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
    AShoorterCharater* PlayerCharacter = Cast<AShoorterCharater>(PlayerPawn);

    if (PlayerCharacter)
    {
        PlayerCharacter->MoveToWaitingPlayerStart();
        PlayerCharacter->EnterWaitingRoomView();
        PlayerCharacter->SetOutfitMaterial(SelectedColorIndex);
    }

    UpdateCharacterPreviewColor(SelectedColorIndex);

    SetUIMode();
}

void UWaitingRoomWidget::SetOwnerMode(bool bOwner)
{
    if (StartGameButton)
    {
        StartGameButton->SetVisibility(
            bOwner ? ESlateVisibility::Visible : ESlateVisibility::Collapsed
        );
    }
}

void UWaitingRoomWidget::OnStartGameClicked()
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
    AShoorterCharater* PlayerCharacter = Cast<AShoorterCharater>(PlayerPawn);

    if (PlayerCharacter)
    {
        PlayerCharacter->ExitWaitingRoomView();
    }

    if (UFBNetworkSubsystem* Net = GetGameInstance()->GetSubsystem<UFBNetworkSubsystem>())
    {
        if (Net->IsConnected())
        {
            Net->SendStartGame();
        }
    }
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

void UWaitingRoomWidget::OnCharacterButton1Clicked()
{
    if (AShoorterCharater* PlayerCharacter =
        Cast<AShoorterCharater>(UGameplayStatics::GetPlayerPawn(this, 0)))
    {
        PlayerCharacter->SetCharacterMesh(0);
    }
}

void UWaitingRoomWidget::OnCharacterButton2Clicked()
{
    if (AShoorterCharater* PlayerCharacter =
        Cast<AShoorterCharater>(UGameplayStatics::GetPlayerPawn(this, 0)))
    {
        PlayerCharacter->SetCharacterMesh(1);
    }
}
void UWaitingRoomWidget::SelectColor(int32 MaterialIndex)
{
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
    AShoorterCharater* PlayerCharacter = Cast<AShoorterCharater>(PlayerPawn);

    if (PlayerCharacter)
    {
        PlayerCharacter->SetOutfitMaterial(MaterialIndex);
    }
}

void UWaitingRoomWidget::SetUIMode()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);

    if (PC)
    {
        PC->SetShowMouseCursor(true);

        FInputModeUIOnly InputMode;
        InputMode.SetWidgetToFocus(TakeWidget());
        InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);

        PC->SetInputMode(InputMode);
    }
}

void UWaitingRoomWidget::UpdateCharacterPreviewColor(int32 ColorIndex)
{

    FLinearColor PreviewColor = FLinearColor::White;

    switch (ColorIndex)
    {
    case 0:
        PreviewColor = FLinearColor(0.2f, 0.8f, 0.2f, 1.0f);
        break;

    case 1:
        PreviewColor = FLinearColor(0.1f, 0.4f, 1.0f, 1.0f);
        break;

    case 2:
        PreviewColor = FLinearColor(0.6f, 0.1f, 1.0f, 1.0f);
        break;

    case 3:
        PreviewColor = FLinearColor(1.0f, 0.75f, 0.1f, 1.0f);
        break;

    default:
        PreviewColor = FLinearColor::White;
        break;
    }

}