// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/BTService_PlayerLocationIfSeen.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBTService_PlayerLocationIfSeen() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTService_BlackboardBase();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_PlayerLocationIfSeen();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_UBTService_PlayerLocationIfSeen_NoRegister();
UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References

// Begin Class UBTService_PlayerLocationIfSeen
void UBTService_PlayerLocationIfSeen::StaticRegisterNativesUBTService_PlayerLocationIfSeen()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBTService_PlayerLocationIfSeen);
UClass* Z_Construct_UClass_UBTService_PlayerLocationIfSeen_NoRegister()
{
	return UBTService_PlayerLocationIfSeen::StaticClass();
}
struct Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BTService_PlayerLocationIfSeen.h" },
		{ "ModuleRelativePath", "BTService_PlayerLocationIfSeen.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SightRadius_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "BTService_PlayerLocationIfSeen.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SightAngle_MetaData[] = {
		{ "Category", "AI" },
		{ "ModuleRelativePath", "BTService_PlayerLocationIfSeen.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SightRadius;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SightAngle;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBTService_PlayerLocationIfSeen>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::NewProp_SightRadius = { "SightRadius", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_PlayerLocationIfSeen, SightRadius), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SightRadius_MetaData), NewProp_SightRadius_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::NewProp_SightAngle = { "SightAngle", nullptr, (EPropertyFlags)0x0020080000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBTService_PlayerLocationIfSeen, SightAngle), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SightAngle_MetaData), NewProp_SightAngle_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::NewProp_SightRadius,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::NewProp_SightAngle,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTService_BlackboardBase,
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::ClassParams = {
	&UBTService_PlayerLocationIfSeen::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::Class_MetaDataParams), Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UBTService_PlayerLocationIfSeen()
{
	if (!Z_Registration_Info_UClass_UBTService_PlayerLocationIfSeen.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBTService_PlayerLocationIfSeen.OuterSingleton, Z_Construct_UClass_UBTService_PlayerLocationIfSeen_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UBTService_PlayerLocationIfSeen.OuterSingleton;
}
template<> SIMPLESHOOTER_API UClass* StaticClass<UBTService_PlayerLocationIfSeen>()
{
	return UBTService_PlayerLocationIfSeen::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UBTService_PlayerLocationIfSeen);
UBTService_PlayerLocationIfSeen::~UBTService_PlayerLocationIfSeen() {}
// End Class UBTService_PlayerLocationIfSeen

// Begin Registration
struct Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_BTService_PlayerLocationIfSeen_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UBTService_PlayerLocationIfSeen, UBTService_PlayerLocationIfSeen::StaticClass, TEXT("UBTService_PlayerLocationIfSeen"), &Z_Registration_Info_UClass_UBTService_PlayerLocationIfSeen, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBTService_PlayerLocationIfSeen), 3950715196U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_BTService_PlayerLocationIfSeen_h_3863339756(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_BTService_PlayerLocationIfSeen_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_BTService_PlayerLocationIfSeen_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
