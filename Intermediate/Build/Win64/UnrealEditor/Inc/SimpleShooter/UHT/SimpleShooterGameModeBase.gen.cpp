// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/SimpleShooterGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSimpleShooterGameModeBase() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_ASimpleShooterGameModeBase();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_ASimpleShooterGameModeBase_NoRegister();
UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References

// Begin Class ASimpleShooterGameModeBase
void ASimpleShooterGameModeBase::StaticRegisterNativesASimpleShooterGameModeBase()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASimpleShooterGameModeBase);
UClass* Z_Construct_UClass_ASimpleShooterGameModeBase_NoRegister()
{
	return ASimpleShooterGameModeBase::StaticClass();
}
struct Z_Construct_UClass_ASimpleShooterGameModeBase_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "SimpleShooterGameModeBase.h" },
		{ "ModuleRelativePath", "SimpleShooterGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASimpleShooterGameModeBase>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::ClassParams = {
	&ASimpleShooterGameModeBase::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ASimpleShooterGameModeBase()
{
	if (!Z_Registration_Info_UClass_ASimpleShooterGameModeBase.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASimpleShooterGameModeBase.OuterSingleton, Z_Construct_UClass_ASimpleShooterGameModeBase_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ASimpleShooterGameModeBase.OuterSingleton;
}
template<> SIMPLESHOOTER_API UClass* StaticClass<ASimpleShooterGameModeBase>()
{
	return ASimpleShooterGameModeBase::StaticClass();
}
ASimpleShooterGameModeBase::ASimpleShooterGameModeBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ASimpleShooterGameModeBase);
ASimpleShooterGameModeBase::~ASimpleShooterGameModeBase() {}
// End Class ASimpleShooterGameModeBase

// Begin Registration
struct Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_SimpleShooterGameModeBase_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ASimpleShooterGameModeBase, ASimpleShooterGameModeBase::StaticClass, TEXT("ASimpleShooterGameModeBase"), &Z_Registration_Info_UClass_ASimpleShooterGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASimpleShooterGameModeBase), 270461550U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_SimpleShooterGameModeBase_h_1951639106(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_SimpleShooterGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_SimpleShooterGameModeBase_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
