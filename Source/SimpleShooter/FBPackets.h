#pragma once

#include "CoreMinimal.h"

// 서버 Protocol.h와 동일한 구조 (동기화 필수)
// SC_MOVE는 Windows.h 매크로 충돌로 SC_PLAYER_MOVE로 대체

#pragma pack(push, 1)

enum class EFBPacketId : uint16
{
    CS_LOGIN        = 1,
    CS_ENTER_ROOM   = 2,
    CS_LEAVE_ROOM   = 3,
    CS_MOVE         = 10,
    CS_ANIM_STATE   = 11,
    CS_DAMAGE       = 12,
    CS_ITEM_STATE   = 13,
    CS_THROW_BOMB   = 14,
    CS_CHAT         = 20,

    SC_LOGIN_RES        = 1001,
    SC_ENTER_GAME       = 1002,
    SC_PLAYER_ENTER     = 1003,
    SC_PLAYER_LEAVE     = 1004,
    SC_PLAYER_MOVE      = 1010,
    SC_ANIM_STATE       = 1011,
    SC_HIT              = 1012,
    SC_ITEM_STATE       = 1013,
    SC_THROW_BOMB       = 1014,
    SC_CHAT             = 1020,
    SC_GAME_END         = 1030,
};

struct FB_PacketHeader
{
    uint16 size;
    uint16 id;
};

struct FB_CS_LOGIN_PKT
{
    FB_PacketHeader h;
    wchar_t name[16];
};

struct FB_CS_ENTER_ROOM_PKT
{
    FB_PacketHeader h;
    uint32 roomId;
};

struct FB_CS_LEAVE_ROOM_PKT
{
    FB_PacketHeader h;
};

struct FB_CS_MOVE_PKT
{
    FB_PacketHeader h;
    float x, y, z;
    float yaw;
    float vx, vy, vz;
};

struct FB_CS_ANIM_STATE_PKT
{
    FB_PacketHeader h;
    uint8 state;
};

struct FB_CS_DAMAGE_PKT
{
    FB_PacketHeader h;
    uint64 targetId;
    float  amount;
};

struct FB_CS_ITEM_STATE_PKT
{
    FB_PacketHeader h;
    uint8 itemType; // 0=없음, 1=총, 2=배트, 3=하키, 4=폭탄
};

struct FB_CS_THROW_BOMB_PKT
{
    FB_PacketHeader h;
    float x, y, z;
    float yaw;
    float pitch;
};

struct FB_CS_CHAT_PKT
{
    FB_PacketHeader h;
    wchar_t msg[128];
};

struct FB_SC_LOGIN_RES_PKT
{
    FB_PacketHeader h;
    uint64 playerId;
    uint8  success;
};

struct FB_PlayerSnapshot
{
    uint64  playerId;
    float   x, y, z;
    float   yaw;
    wchar_t name[16];
};

struct FB_SC_ENTER_GAME_PKT
{
    FB_PacketHeader h;
    uint64 myPlayerId;
    uint8  otherCount;
};

struct FB_SC_PLAYER_ENTER_PKT
{
    FB_PacketHeader    h;
    FB_PlayerSnapshot  p;
};

struct FB_SC_PLAYER_LEAVE_PKT
{
    FB_PacketHeader h;
    uint64 playerId;
};

struct FB_SC_PLAYER_MOVE_PKT
{
    FB_PacketHeader h;
    uint64 playerId;
    float  x, y, z;
    float  yaw;
    float  vx, vy, vz;
};

struct FB_SC_ANIM_STATE_PKT
{
    FB_PacketHeader h;
    uint64 playerId;
    uint8  state;
};

struct FB_SC_HIT_PKT
{
    FB_PacketHeader h;
    uint64 attackerId;
    uint64 targetId;
    float  amount;
    float  remainHp;
};

struct FB_SC_GAME_END_PKT
{
    FB_PacketHeader h;
    uint64 winnerId; // 0 이면 무승부
};

struct FB_SC_ITEM_STATE_PKT
{
    FB_PacketHeader h;
    uint64 playerId;
    uint8  itemType;
};

struct FB_SC_THROW_BOMB_PKT
{
    FB_PacketHeader h;
    uint64 playerId;
    float  x, y, z;
    float  yaw;
    float  pitch;
};

struct FB_SC_CHAT_PKT
{
    FB_PacketHeader h;
    uint64  playerId;
    wchar_t msg[128];
};

#pragma pack(pop)

enum class EFBItemType : uint8
{
    None   = 0,
    Gun    = 1,
    Bat    = 2,
    Hockey = 3,
    Bomb   = 4,
};

enum class EFBAnimState : uint8
{
    Normal  = 0,
    Attack  = 1,
    Hit     = 2,
    Stunned = 3,
    Recover = 4,
    Dead    = 5,
};
