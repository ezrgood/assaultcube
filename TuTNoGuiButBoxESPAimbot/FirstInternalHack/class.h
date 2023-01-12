#pragma once
//#include <iostream>
//#include <cstdio>
//#include <cstdint>
#include <windows.h>
#include "geom.h"

//struct Vector3 { float x, y, z; };
//
//void printVector(const Vector3& v)
//{
//	std::cout << "\r X, " << v.x << " Y, " << v.y << " Z, " << v.z << "" << std::flush;
//}


enum gameModes
{
	TEAMDEATHMATCH = 0,
	COOPEDIT,
	DEATHMATCH,
	SURVIVOR,
	TEAMSURVIVOR,
	CTF,
	PISTOLFRENZY,
	BOTTEAMDEATHMATCH,
	BOTDEATHMATCH,
	LASTSWISSSTANDING,
	ONESHOTONEKILL,
	TEAMONESHOTONEKILL,
	BOTONESHOTONEKILL,
	HUNTTHEFLAG,
	TEAMKEEPTHEFLAG,
	KEEPTHEFLAG,
	TEAMPF,
	TEAMLSS,
	BOTPISTOLFRENZY,
	BOtlSS,
	BOTTEAMSURVIVOR,
	BOTTEAMONESHOTONEKILL,
	NUM
};




class ent;

class ent
{
public:
	DWORD vTable; //0x0000
	Vector3 head; //0x0004
	Vector3 Velocity; //0x0010
	char pad_001C[24]; //0x001C
	Vector3 pos; //0x0034
	float Yaw; //0x0040
	float Pitch; //0x0044
	float Roll; //0x0048
	float PitchVel; //0x004C
	float MaxSpeed; //0x0050
	int32_t Airtime; //0x0054
	float Radius; //0x0058
	float Height; //0x005C
	float NormalHight; //0x0060
	float HightAboveHead; //0x0064
	int8_t IsInWater; //0x0068
	int8_t IsInAir; //0x0069
	int8_t IsOnLadder; //0x006A
	int8_t JumpNext; //0x006B
	int8_t Crouching; //0x006C
	int8_t AirCrouch; //0x006D
	char pad_006E[1]; //0x006E
	int8_t CanCollide; //0x006F
	int8_t IsNotInGame; //0x0070
	int8_t Scoping; //0x0071
	int8_t Shooting; //0x0072
	char pad_0073[5]; //0x0073
	float LastJumpPos; //0x0078
	int32_t LastSplash; //0x007C
	int8_t Move; //0x0080
	int8_t Strafe; //0x0081
	int8_t noClip; //0x0082
	int8_t invis; //0x0083
	char pad_0084[116]; //0x0084
	int32_t health; //0x00F8
	int32_t armor; //0x00FC
	int32_t Primary; //0x0100
	char pad_0104[4]; //0x0104
	int32_t GunSelect; //0x0108
	int8_t AkimboEquipped; //0x010C
	char pad_010D[7]; //0x010D
	int32_t SecAmmoReserve; //0x0114
	int32_t PrimaryAmmoReserveCarbine; //0x0118
	int32_t PrimaryAmmoReserveShotgun; //0x011C
	int32_t PrimaryAmmoReserveSubGun; //0x0120
	int32_t PrimaryAmmoReserveSniper; //0x0124
	int32_t PrimaryAmmoReserveAssault; //0x0128
	char pad_012C[16]; //0x012C
	int32_t SecAmmo; //0x013C
	int32_t CarbineAmmo; //0x0140
	int32_t ShotgunAmmo; //0x0144
	int32_t SubGunAmmo; //0x0148
	int32_t SniperAmmo; //0x014C
	int32_t AssaultAmmo; //0x0150
	char pad_0154[4]; //0x0154
	int32_t GrenadeAmmo; //0x0158
	int32_t AkimboAmmo; //0x015C
	int32_t MeleeDelayTime; //0x0160
	int32_t SecDelayTime; //0x0164
	int32_t CarbineDelayTime; //0x0168
	int32_t ShotgunDelayTime; //0x016C
	int32_t SubGunDelayTime; //0x0170
	int32_t SniperDelayTime; //0x0174
	int32_t AssaultDelayTime; //0x0178
	char pad_017C[4]; //0x017C
	int32_t GrenadeDelayTime; //0x0180
	int32_t AkimboDelayTime; //0x0184
	int32_t MeleeShotsFired; //0x0188
	char pad_018C[4]; //0x018C
	int32_t CarbineShotsFired; //0x0190
	int32_t ShotgunShotsFired; //0x0194
	int32_t SubGunShotsFired; //0x0198
	int32_t SniperShotsFired; //0x019C
	int32_t AssaultShotsFired; //0x01A0
	char pad_01A4[4]; //0x01A4
	int32_t GrenadeShotsFired; //0x01A8
	int32_t AkimboShotsFired; //0x01AC
	char pad_01B0[44]; //0x01B0
	int32_t Skin; //0x01DC
	int32_t NextSkin; //0x01E0
	int32_t ClientID; //0x01E4
	int32_t LastUpdate; //0x01E8
	int32_t Lag; //0x01EC
	int32_t Ping; //0x01F0
	uint32_t IpAddress; //0x01F4
	int32_t TimesRespawned; //0x01F8
	int32_t Kills; //0x01FC
	int32_t FlagScore; //0x0200
	int32_t Deaths; //0x0204
	int32_t Score; //0x0208
	int32_t TeamKills; //0x020C
	int32_t LastAction; //0x0210
	int32_t LastMove; //0x0214
	int32_t LastHurt; //0x0218
	int32_t LastVoiceCom; //0x021C
	int32_t ClientRole; //0x0220
	int8_t bAttacking; //0x0224
	char name[16]; //0x0225
	char pad_0235[247]; //0x0235
	int8_t team; //0x032C
	char pad_032D[11]; //0x032D
	int8_t state; //0x0338
	char pad_0339[59]; //0x0339
	class weapon* currWeapon; //0x0374
	char pad_0378[3364]; //0x0378
}; //Size: 0x109C
static_assert(sizeof(ent) == 0x109C);

class weapon
{
public:
	char pad_0000[4]; //0x0000
	int32_t weaponid; //0x0004
	class ent* owner; //0x0008
	char pad_000C[4]; //0x000C
	class ammoPtr* ammoReserve; //0x0010
	class ammoPtr* ammoClip; //0x0014
	char pad_0018[44]; //0x0018
}; //Size: 0x0044
static_assert(sizeof(weapon) == 0x44);

class ammoPtr
{
public:
	int32_t ammo; //0x0000
}; //Size: 0x0004
static_assert(sizeof(ammoPtr) == 0x4);





struct entList
{
	ent* ents[31];
};



