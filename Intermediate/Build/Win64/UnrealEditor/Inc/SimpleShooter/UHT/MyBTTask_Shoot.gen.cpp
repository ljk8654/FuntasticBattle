// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/MyBTTask_Shoot.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyBTTask_Shoot() {}

// Begin Cross Module References
AIMODULE_API UClass* Z_Construct_UClass_UBTTaskNode();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_UMyBTTask_Shoot();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_UMyBTTask_Shoot_NoRegister();
UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References

// Begin Class UMyBTTask_Shoot
void UMyBTTask_Shoot::StaticRegisterNativesUMyBTTask_Shoot()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyBTTask_Shoot);
UClass* Z_Construct_UClass_UMyBTTask_Shoot_NoRegister()
{
	return UMyBTTask_Shoot::StaticClass();
}
struct Z_Construct_UClass_UMyBTTask_Shoot_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "MyBTTask_Shoot.h" },
		{ "ModuleRelativePath", "MyBTTask_Shoot.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyBTTask_Shoot>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UMyBTTask_Shoot_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBTTaskNode,
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyBTTask_Shoot_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyBTTask_Shoot_Statics::ClassParams = {
	&UMyBTTask_Shoot::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyBTTask_Shoot_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyBTTask_Shoot_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UMyBTTask_Shoot()
{
	if (!Z_Registration_Info_UClass_UMyBTTask_Shoot.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyBTTask_Shoot.OuterSingleton, Z_Construct_UClass_UMyBTTask_Shoot_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UMyBTTask_Shoot.OuterSingleton;
}
template<> SIMPLESHOOTER_API UClass* StaticClass<UMyBTTask_Shoot>()
{
	return UMyBTTask_Shoot::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UMyBTTask_Shoot);
UMyBTTask_Shoot::~UMyBTTask_Shoot() {}
// End Class UMyBTTask_Shoot

// Begin Registration
struct Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_MyBTTask_Shoot_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UMyBTTask_Shoot, UMyBTTask_Shoot::StaticClass, TEXT("UMyBTTask_Shoot"), &Z_Registration_Info_UClass_UMyBTTask_Shoot, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyBTTask_Shoot), 2095160742U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_MyBTTask_Shoot_h_3781779337(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_MyBTTask_Shoot_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_MyBTTask_Shoot_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
