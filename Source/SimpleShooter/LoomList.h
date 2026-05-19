#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoomList.generated.h"

class URoomButton;
class USoundBase;
class UScrollBox;
class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnterRoomSuccess);

UCLASS()
class SIMPLESHOOTER_API ULoomList : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    void AddRoom(const FString& RoomName);

    UPROPERTY(BlueprintAssignable)
    FOnEnterRoomSuccess OnEnterRoomSuccess;

protected:
    UPROPERTY(meta = (BindWidget))
    UScrollBox* RoomListBox;

    UPROPERTY(meta = (BindWidget))
    UButton* CreateRoomButton;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
    TSubclassOf<URoomButton> RoomButtonClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sound")
    USoundBase* ClickSound;

    int RoomCounter = 1;

    UFUNCTION()
    void OnCreateRoomClicked();

    UFUNCTION()
    void OnRoomSelected(const FString& RoomName);

    UFUNCTION()
    void OnEnterGameReceived(int64 MyPlayerId, int32 OtherCount, bool bIsOwner);
};
