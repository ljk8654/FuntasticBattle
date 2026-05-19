#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Tickable.h"
#include "FBPackets.h"
#include "FBNetworkSubsystem.generated.h"

class FSocket;
class FNetworkRecvWorker;

UCLASS()
class SIMPLESHOOTER_API UFBNetworkSubsystem : public UGameInstanceSubsystem, public FTickableGameObject
{
    GENERATED_BODY()

public:
    // USubsystem
    virtual void Initialize(FSubsystemCollectionBase& Collection) override;
    virtual void Deinitialize() override;

    // FTickableGameObject
    virtual void Tick(float DeltaTime) override;
    virtual TStatId GetStatId() const override;
    virtual bool IsTickable() const override { return true; }
    virtual bool IsTickableInEditor() const override { return false; }

    // 연결 관리
    bool Connect(const FString& Host, int32 Port);
    void Disconnect();
    bool IsConnected() const { return bConnected; }
    int64 GetMyPlayerId() const { return MyPlayerId; }

    // 패킷 송신
    void SendLogin(const FString& PlayerName);
    void SendEnterRoom(uint32 RoomId);
    void SendMove(const FVector& Pos, float Yaw, const FVector& Vel);
    void SendAnimState(uint8 State);
    void SendDamage(int64 TargetId, float Amount);
    void SendItemState(uint8 ItemType);
    void SendThrowBomb(const FVector& Pos, float Yaw, float Pitch);
    void SendChat(const FString& Msg);
    void SendItemDrop(uint8 ItemType, const FVector& Pos);
    void SendItemPickup(const FVector& Pos);
    void SendStartGame();

    // 게임 스레드 이벤트 델리게이트
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLoginResult, int64, PlayerId, bool, bSuccess);
    UPROPERTY(BlueprintAssignable)
    FOnLoginResult OnLoginResult;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEnterGame, int64, MyPlayerId, int32, OtherCount, bool, bIsOwner);
    UPROPERTY(BlueprintAssignable)
    FOnEnterGame OnEnterGame;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnRemotePlayerEnter, int64, PlayerId, FVector, InitPos, float, InitYaw);
    UPROPERTY(BlueprintAssignable)
    FOnRemotePlayerEnter OnRemotePlayerEnter;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemotePlayerLeave, int64, PlayerId);
    UPROPERTY(BlueprintAssignable)
    FOnRemotePlayerLeave OnRemotePlayerLeave;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnRemotePlayerMove, int64, PlayerId, FVector, NewPos, float, NewYaw, FVector, NewVel);
    UPROPERTY(BlueprintAssignable)
    FOnRemotePlayerMove OnRemotePlayerMove;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRemotePlayerAnim, int64, PlayerId, uint8, State);
    UPROPERTY(BlueprintAssignable)
    FOnRemotePlayerAnim OnRemotePlayerAnim;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRemotePlayerChat, int64, PlayerId, FString, Message);
    UPROPERTY(BlueprintAssignable)
    FOnRemotePlayerChat OnRemotePlayerChat;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRemoteItemState, int64, PlayerId, uint8, ItemType);
    UPROPERTY(BlueprintAssignable)
    FOnRemoteItemState OnRemoteItemState;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnRemoteThrowBomb, int64, PlayerId, FVector, Pos, float, Yaw, float, Pitch);
    UPROPERTY(BlueprintAssignable)
    FOnRemoteThrowBomb OnRemoteThrowBomb;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHit, int64, AttackerId, int64, TargetId, float, Amount, float, RemainHp);
    UPROPERTY(BlueprintAssignable)
    FOnHit OnHit;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameEnd, int64, WinnerId, bool, bIsWinner);
    UPROPERTY(BlueprintAssignable)
    FOnGameEnd OnGameEnd;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRemoteItemDrop, uint8, ItemType, FVector, Pos);
    UPROPERTY(BlueprintAssignable)
    FOnRemoteItemDrop OnRemoteItemDrop;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRemoteItemPickup, FVector, Pos);
    UPROPERTY(BlueprintAssignable)
    FOnRemoteItemPickup OnRemoteItemPickup;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGameStart, uint8, SpawnIndex, int32, ItemSeed);
    UPROPERTY(BlueprintAssignable)
    FOnGameStart OnGameStart;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDisconnected);
    UPROPERTY(BlueprintAssignable)
    FOnDisconnected OnDisconnected;

private:
    FSocket*             Socket     = nullptr;
    FNetworkRecvWorker*  RecvWorker = nullptr;
    FRunnableThread*     RecvThread = nullptr;

    TAtomic<bool>   bConnected { false };
    int64           MyPlayerId = 0;

    // 수신 스레드가 push, 게임 스레드가 pop
    TQueue<TArray<uint8>, EQueueMode::Mpsc> IncomingQueue;

    void ProcessIncomingQueue();
    void HandlePacket(const uint8* Data, int32 Size);
    bool SendRaw(const void* Data, int32 Size);
};
