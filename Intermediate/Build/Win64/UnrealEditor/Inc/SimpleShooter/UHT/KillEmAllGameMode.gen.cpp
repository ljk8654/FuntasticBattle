// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/KillEmAllGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeKillEmAllGameMode() {}

// Begin Cross Module References
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AKillEmAllGameMode();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AKillEmAllGameMode_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_ASimpleShooterGameModeBase();
UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References

// Begin Class AKillEmAllGameMode
void AKillEmAllGameMode::StaticRegisterNativesAKillEmAllGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AKillEmAllGameMode);
UClass* Z_Construct_UClass_AKillEmAllGameMode_NoRegister()
{
	return AKillEmAllGameMode::StaticClass();
}
struct Z_Construct_UClass_AKillEmAllGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "KillEmAllGameMode.h" },
		{ "ModuleRelativePath", "KillEmAllGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKillEmAllGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_AKillEmAllGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ASimpleShooterGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AKillEmAllGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AKillEmAllGameMode_Statics::ClassParams = {
	&AKillEmAllGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AKillEmAllGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AKillEmAllGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AKillEmAllGameMode()
{
	if (!Z_Registration_Info_UClass_AKillEmAllGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AKillEmAllGameMode.OuterSingleton, Z_Construct_UClass_AKillEmAllGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AKillEmAllGameMode.OuterSingleton;
}
template<> SIMPLESHOOTER_API UClass* StaticClass<AKillEmAllGameMode>()
{
	return AKillEmAllGameMode::StaticClass();
}
AKillEmAllGameMode::AKillEmAllGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AKillEmAllGameMode);
AKillEmAllGameMode::~AKillEmAllGameMode() {}
// End Class AKillEmAllGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_KillEmAllGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AKillEmAllGameMode, AKillEmAllGameMode::StaticClass, TEXT("AKillEmAllGameMode"), &Z_Registration_Info_UClass_AKillEmAllGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AKillEmAllGameMode), 2284785389U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_KillEmAllGameMode_h_1933145492(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_KillEmAllGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_KillEmAllGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
