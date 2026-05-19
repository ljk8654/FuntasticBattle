// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleShooter_init() {}
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_SimpleShooter_OnEnterRoomSuccess__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_SimpleShooter_OnLoginSuccess__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_SimpleShooter_OnRoomClicked__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnDisconnected__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnEnterGame__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnGameEnd__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnHit__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnLoginResult__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerAnim__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerChat__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerEnter__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerLeave__DelegateSignature();
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerMove__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SimpleShooter;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SimpleShooter()
	{
		if (!Z_Registration_Info_UPackage__Script_SimpleShooter.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SimpleShooter_OnEnterRoomSuccess__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SimpleShooter_OnLoginSuccess__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SimpleShooter_OnRoomClicked__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnDisconnected__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnEnterGame__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnGameEnd__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnHit__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnLoginResult__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerAnim__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerChat__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerEnter__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerLeave__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_UFBNetworkSubsystem_OnRemotePlayerMove__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SimpleShooter",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x862153AC,
				0xC5235035,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SimpleShooter.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SimpleShooter.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SimpleShooter(Z_Construct_UPackage__Script_SimpleShooter, TEXT("/Script/SimpleShooter"), Z_Registration_Info_UPackage__Script_SimpleShooter, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x862153AC, 0xC5235035));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
