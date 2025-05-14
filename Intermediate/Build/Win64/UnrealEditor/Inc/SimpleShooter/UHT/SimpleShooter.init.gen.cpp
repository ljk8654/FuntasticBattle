// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleShooter_init() {}
	SIMPLESHOOTER_API UFunction* Z_Construct_UDelegateFunction_SimpleShooter_OnLoginSuccess__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SimpleShooter;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SimpleShooter()
	{
		if (!Z_Registration_Info_UPackage__Script_SimpleShooter.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SimpleShooter_OnLoginSuccess__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SimpleShooter",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x65DAAB10,
				0x143879F9,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SimpleShooter.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SimpleShooter.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SimpleShooter(Z_Construct_UPackage__Script_SimpleShooter, TEXT("/Script/SimpleShooter"), Z_Registration_Info_UPackage__Script_SimpleShooter, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x65DAAB10, 0x143879F9));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
