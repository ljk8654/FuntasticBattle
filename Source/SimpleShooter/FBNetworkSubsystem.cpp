#include "FBNetworkSubsystem.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "IPAddress.h"
#include "HAL/RunnableThread.h"

// ---------- Recv Worker ----------

class FNetworkRecvWorker : public FRunnable
{
public:
    FNetworkRecvWorker(FSocket* InSocket, TQueue<TArray<uint8>, EQueueMode::Mpsc>& InQueue)
        : Socket(InSocket), Queue(InQueue) {}

    virtual bool Init() override { return true; }

    virtual uint32 Run() override
    {
        TArray<uint8> Buf;
        Buf.SetNumUninitialized(8192);

        TArray<uint8> Assembly;

        while (!bStopping)
        {
            int32 BytesRead = 0;
            bool bOk = Socket->Recv(Buf.GetData(), Buf.Num(), BytesRead);

            if (!bOk || BytesRead == 0)
                break;

            Assembly.Append(Buf.GetData(), BytesRead);

            int32 ReadIdx = 0;
            while (Assembly.Num() - ReadIdx >= (int32)sizeof(FB_PacketHeader))
            {
                FB_PacketHeader Header;
                FMemory::Memcpy(&Header, Assembly.GetData() + ReadIdx, sizeof(Header));

                if (Header.size < sizeof(FB_PacketHeader))
                    break;

                if (Assembly.Num() - ReadIdx < (int32)Header.size)
                    break;

                TArray<uint8> Packet(Assembly.GetData() + ReadIdx, Header.size);
                Queue.Enqueue(MoveTemp(Packet));
                ReadIdx += Header.size;
            }

            if (ReadIdx > 0)
                Assembly.RemoveAt(0, ReadIdx);
        }

        return 0;
    }

    virtual void Stop() override { bStopping = true; }

private:
    FSocket* Socket;
    TQueue<TArray<uint8>, EQueueMode::Mpsc>& Queue;
    TAtomic<bool> bStopping { false };
};

// ---------- UFBNetworkSubsystem ----------

void UFBNetworkSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
}

void UFBNetworkSubsystem::Deinitialize()
{
    Disconnect();
    Super::Deinitialize();
}

TStatId UFBNetworkSubsystem::GetStatId() const
{
    RETURN_QUICK_DECLARE_CYCLE_STAT(UFBNetworkSubsystem, STATGROUP_Tickables);
}

bool UFBNetworkSubsystem::Connect(const FString& Host, int32 Port)
{
    if (bConnected)
        Disconnect();

    ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
    Socket = SocketSubsystem->CreateSocket(NAME_Stream, TEXT("FBClient"), false);
    if (!Socket)
        return false;

    TSharedRef<FInternetAddr> Addr = SocketSubsystem->CreateInternetAddr();
    bool bIsValid = false;
    Addr->SetIp(*Host, bIsValid);
    if (!bIsValid)
    {
        SocketSubsystem->DestroySocket(Socket);
        Socket = nullptr;
        return false;
    }
    Addr->SetPort(Port);

    if (!Socket->Connect(*Addr))
    {
        SocketSubsystem->DestroySocket(Socket);
        Socket = nullptr;
        return false;
    }

    bConnected = true;

    RecvWorker = new FNetworkRecvWorker(Socket, IncomingQueue);
    RecvThread = FRunnableThread::Create(RecvWorker, TEXT("FBRecvThread"));

    UE_LOG(LogTemp, Log, TEXT("[Network] 서버 연결 성공 %s:%d"), *Host, Port);
    return true;
}

void UFBNetworkSubsystem::Disconnect()
{
    if (!bConnected)
        return;

    bConnected = false;

    if (RecvWorker)
        RecvWorker->Stop();

    if (Socket)
        Socket->Close();

    if (RecvThread)
    {
        RecvThread->WaitForCompletion();
        delete RecvThread;
        RecvThread = nullptr;
    }

    delete RecvWorker;
    RecvWorker = nullptr;

    if (Socket)
    {
        ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
        Socket = nullptr;
    }

    UE_LOG(LogTemp, Log, TEXT("[Network] 연결 해제"));
}

void UFBNetworkSubsystem::Tick(float DeltaTime)
{
    ProcessIncomingQueue();
}

void UFBNetworkSubsystem::ProcessIncomingQueue()
{
    TArray<uint8> Packet;
    while (IncomingQueue.Dequeue(Packet))
    {
        if (Packet.Num() >= (int32)sizeof(FB_PacketHeader))
            HandlePacket(Packet.GetData(), Packet.Num());
    }
}

void UFBNetworkSubsystem::HandlePacket(const uint8* Data, int32 Size)
{
    const FB_PacketHeader* Header = reinterpret_cast<const FB_PacketHeader*>(Data);
    EFBPacketId Id = static_cast<EFBPacketId>(Header->id);

    switch (Id)
    {
    case EFBPacketId::SC_LOGIN_RES:
    {
        const FB_SC_LOGIN_RES_PKT* Pkt = reinterpret_cast<const FB_SC_LOGIN_RES_PKT*>(Data);
        MyPlayerId = static_cast<int64>(Pkt->playerId);
        OnLoginResult.Broadcast(MyPlayerId, Pkt->success != 0);
        break;
    }
    case EFBPacketId::SC_ENTER_GAME:
    {
        const FB_SC_ENTER_GAME_PKT* Pkt = reinterpret_cast<const FB_SC_ENTER_GAME_PKT*>(Data);
        OnEnterGame.Broadcast(static_cast<int64>(Pkt->myPlayerId), static_cast<int32>(Pkt->otherCount));
        break;
    }
    case EFBPacketId::SC_PLAYER_ENTER:
    {
        const FB_SC_PLAYER_ENTER_PKT* Pkt = reinterpret_cast<const FB_SC_PLAYER_ENTER_PKT*>(Data);
        FVector Pos(Pkt->p.x, Pkt->p.y, Pkt->p.z);
        OnRemotePlayerEnter.Broadcast(static_cast<int64>(Pkt->p.playerId), Pos, Pkt->p.yaw);
        break;
    }
    case EFBPacketId::SC_PLAYER_LEAVE:
    {
        const FB_SC_PLAYER_LEAVE_PKT* Pkt = reinterpret_cast<const FB_SC_PLAYER_LEAVE_PKT*>(Data);
        OnRemotePlayerLeave.Broadcast(static_cast<int64>(Pkt->playerId));
        break;
    }
    case EFBPacketId::SC_PLAYER_MOVE:
    {
        const FB_SC_PLAYER_MOVE_PKT* Pkt = reinterpret_cast<const FB_SC_PLAYER_MOVE_PKT*>(Data);
        FVector Pos(Pkt->x, Pkt->y, Pkt->z);
        OnRemotePlayerMove.Broadcast(static_cast<int64>(Pkt->playerId), Pos, Pkt->yaw);
        break;
    }
    case EFBPacketId::SC_ANIM_STATE:
    {
        const FB_SC_ANIM_STATE_PKT* Pkt = reinterpret_cast<const FB_SC_ANIM_STATE_PKT*>(Data);
        OnRemotePlayerAnim.Broadcast(static_cast<int64>(Pkt->playerId), Pkt->state);
        break;
    }
    case EFBPacketId::SC_HIT:
    {
        const FB_SC_HIT_PKT* Pkt = reinterpret_cast<const FB_SC_HIT_PKT*>(Data);
        OnHit.Broadcast(
            static_cast<int64>(Pkt->attackerId),
            static_cast<int64>(Pkt->targetId),
            Pkt->amount,
            Pkt->remainHp);
        break;
    }
    case EFBPacketId::SC_GAME_END:
    {
        const FB_SC_GAME_END_PKT* Pkt = reinterpret_cast<const FB_SC_GAME_END_PKT*>(Data);
        bool bIsWinner = (static_cast<int64>(Pkt->winnerId) == MyPlayerId);
        OnGameEnd.Broadcast(static_cast<int64>(Pkt->winnerId), bIsWinner);
        break;
    }
    case EFBPacketId::SC_CHAT:
    {
        const FB_SC_CHAT_PKT* Pkt = reinterpret_cast<const FB_SC_CHAT_PKT*>(Data);
        FString Msg(Pkt->msg);
        OnRemotePlayerChat.Broadcast(static_cast<int64>(Pkt->playerId), Msg);
        break;
    }
    default:
        UE_LOG(LogTemp, Warning, TEXT("[Network] 알 수 없는 패킷 id=%d"), Header->id);
        break;
    }
}

bool UFBNetworkSubsystem::SendRaw(const void* Data, int32 Size)
{
    if (!bConnected || !Socket)
        return false;

    int32 BytesSent = 0;
    return Socket->Send(static_cast<const uint8*>(Data), Size, BytesSent) && BytesSent == Size;
}

void UFBNetworkSubsystem::SendLogin(const FString& PlayerName)
{
    FB_CS_LOGIN_PKT Pkt{};
    Pkt.h.size = sizeof(Pkt);
    Pkt.h.id   = static_cast<uint16>(EFBPacketId::CS_LOGIN);
    FCString::Strncpy(Pkt.name, *PlayerName, 16);
    SendRaw(&Pkt, sizeof(Pkt));
}

void UFBNetworkSubsystem::SendEnterRoom(uint32 RoomId)
{
    FB_CS_ENTER_ROOM_PKT Pkt{};
    Pkt.h.size  = sizeof(Pkt);
    Pkt.h.id    = static_cast<uint16>(EFBPacketId::CS_ENTER_ROOM);
    Pkt.roomId  = RoomId;
    SendRaw(&Pkt, sizeof(Pkt));
}

void UFBNetworkSubsystem::SendMove(const FVector& Pos, float Yaw, const FVector& Vel)
{
    FB_CS_MOVE_PKT Pkt{};
    Pkt.h.size = sizeof(Pkt);
    Pkt.h.id   = static_cast<uint16>(EFBPacketId::CS_MOVE);
    Pkt.x = Pos.X; Pkt.y = Pos.Y; Pkt.z = Pos.Z;
    Pkt.yaw = Yaw;
    Pkt.vx = Vel.X; Pkt.vy = Vel.Y; Pkt.vz = Vel.Z;
    SendRaw(&Pkt, sizeof(Pkt));
}

void UFBNetworkSubsystem::SendAnimState(uint8 State)
{
    FB_CS_ANIM_STATE_PKT Pkt{};
    Pkt.h.size  = sizeof(Pkt);
    Pkt.h.id    = static_cast<uint16>(EFBPacketId::CS_ANIM_STATE);
    Pkt.state   = State;
    SendRaw(&Pkt, sizeof(Pkt));
}

void UFBNetworkSubsystem::SendDamage(int64 TargetId, float Amount)
{
    FB_CS_DAMAGE_PKT Pkt{};
    Pkt.h.size    = sizeof(Pkt);
    Pkt.h.id      = static_cast<uint16>(EFBPacketId::CS_DAMAGE);
    Pkt.targetId  = static_cast<uint64>(TargetId);
    Pkt.amount    = Amount;
    SendRaw(&Pkt, sizeof(Pkt));
}

void UFBNetworkSubsystem::SendChat(const FString& Msg)
{
    FB_CS_CHAT_PKT Pkt{};
    Pkt.h.size = sizeof(Pkt);
    Pkt.h.id   = static_cast<uint16>(EFBPacketId::CS_CHAT);
    FCString::Strncpy(Pkt.msg, *Msg, 128);
    SendRaw(&Pkt, sizeof(Pkt));
}
