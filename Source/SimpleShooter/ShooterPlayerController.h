#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HUDWidget.h"
#include "LoomList.h"
#include "LoginWidget.h"
#include "WaitingRoomWidget.h"
#include "ShooterPlayerController.generated.h"

class ARemotePlayer;
class AHeart;
class ABomb;

UCLASS()
class SIMPLESHOOTER_API AShooterPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;

    bool IsOwnerInWaitingRoom() const { return bIsOwner && WaitingRoomWidget != nullptr; }


    UPROPERTY(EditAnywhere, Category="UI")
    TSubclassOf<UHUDWidget> HUDClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
    TSubclassOf<ULoginWidget> LoginWidgetClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
    TSubclassOf<ULoomList> RoomListClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
    TSubclassOf<UWaitingRoomWidget> WaitingRoomWidgetClass;

    // 원격 플레이어 BP 클래스 (BP_RemotePlayer를 BP에서 지정)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Network")
    TSubclassOf<ARemotePlayer> RemotePlayerClass;

    // NPC 드롭 아이템 클래스 (BP_ShooterPlayerController에서 지정)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drop")
    TSubclassOf<AHeart> HeartDropClass;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Drop")
    TSubclassOf<ABomb> BombDropClass;

    UPROPERTY()
    ULoginWidget* CurrentLoginWidget;

    UFUNCTION()
    void OnLoginSuccess();

    UFUNCTION()
    void OnEnterRoomSuccess();

    UHUDWidget* GetHUDWidget() const { return HUD; }

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<class UUserWidget> WinnerScreenClass;

    UPROPERTY(EditAnywhere)
    TSubclassOf<class UUserWidget> LoseScreenClass;

    UPROPERTY(EditAnywhere)
    float RestartDelay = 5.f;

    FTimerHandle RestartTimer;

    UPROPERTY()
    UHUDWidget* HUD;

    UPROPERTY()
    ULoomList* RoomList;

    UPROPERTY()
    UWaitingRoomWidget* WaitingRoomWidget;

    // 원격 플레이어 맵
    UPROPERTY()
    TMap<int64, ARemotePlayer*> RemotePlayers;

    // 네트워크 이벤트 핸들러
    UFUNCTION()
    void OnRemotePlayerEnter(int64 PlayerId, FVector InitPos, float InitYaw);

    UFUNCTION()
    void OnRemotePlayerLeave(int64 PlayerId);

    UFUNCTION()
    void OnRemotePlayerMove(int64 PlayerId, FVector NewPos, float NewYaw, FVector NewVel);

    UFUNCTION()
    void OnRemoteAnimState(int64 PlayerId, uint8 State);

    UFUNCTION()
    void OnHitReceived(int64 AttackerId, int64 TargetId, float Amount, float RemainHp);

    UFUNCTION()
    void OnGameEndReceived(int64 WinnerId, bool bIsWinner);

    UFUNCTION()
    void OnServerDisconnected();

    UFUNCTION()
    void OnRemoteItemStateReceived(int64 PlayerId, uint8 ItemType);

    UFUNCTION()
    void OnRemoteThrowBombReceived(int64 PlayerId, FVector Pos, float Yaw, float Pitch);

    UFUNCTION()
    void OnRemoteItemDropReceived(uint8 ItemType, FVector Pos);

    UFUNCTION()
    void OnRemoteItemPickupReceived(FVector Pos);

    UFUNCTION()
    void OnEnterGameReceived(int64 MyPlayerId, int32 OtherCount, bool bOwner);

    UFUNCTION()
    void OnGameStartReceived(uint8 SpawnIndex, int32 ItemSeed);

    void ExitGame();


    bool bIsOwner = false;

    // 에디터에서 게임 시작 시 아이템을 스폰할 위치들을 등록
    UPROPERTY(EditAnywhere, Category="GameStart")
    TArray<FVector> ItemDropSpawnPoints;
};
