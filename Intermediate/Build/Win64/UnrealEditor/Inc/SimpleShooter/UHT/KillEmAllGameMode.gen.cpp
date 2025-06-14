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
ENGINE_API UClass* Z_Construct_UClass_USoundBase_NoRegister();
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BackgroundMusic_MetaData[] = {
		{ "Category", "BGM" },
		{ "ModuleRelativePath", "KillEmAllGameMode.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_BackgroundMusic;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AKillEmAllGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AKillEmAllGameMode_Statics::NewProp_BackgroundMusic = { "BackgroundMusic", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AKillEmAllGameMode, BackgroundMusic), Z_Construct_UClass_USoundBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BackgroundMusic_MetaData), NewProp_BackgroundMusic_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AKillEmAllGameMode_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AKillEmAllGameMode_Statics::NewProp_BackgroundMusic,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AKillEmAllGameMode_Statics::PropPointers) < 2048);
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
	Z_Construct_UClass_AKillEmAllGameMode_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AKillEmAllGameMode_Statics::PropPointers),
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
		{ Z_Construct_UClass_AKillEmAllGameMode, AKillEmAllGameMode::StaticClass, TEXT("AKillEmAllGameMode"), &Z_Registration_Info_UClass_AKillEmAllGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AKillEmAllGameMode), 20547453U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_KillEmAllGameMode_h_1303530553(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_KillEmAllGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_KillEmAllGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
