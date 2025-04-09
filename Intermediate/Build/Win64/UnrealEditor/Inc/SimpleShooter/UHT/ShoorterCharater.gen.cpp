// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/ShoorterCharater.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShoorterCharater() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
ENGINE_API UClass* Z_Construct_UClass_ACharacter();
ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AGun_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShoorterCharater();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShoorterCharater_NoRegister();
UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References

// Begin Class AShoorterCharater Function EnableMovement
struct Z_Construct_UFunction_AShoorterCharater_EnableMovement_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShoorterCharater_EnableMovement_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShoorterCharater, nullptr, "EnableMovement", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_EnableMovement_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShoorterCharater_EnableMovement_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AShoorterCharater_EnableMovement()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShoorterCharater_EnableMovement_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShoorterCharater::execEnableMovement)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EnableMovement();
	P_NATIVE_END;
}
// End Class AShoorterCharater Function EnableMovement

// Begin Class AShoorterCharater Function IsDead
struct Z_Construct_UFunction_AShoorterCharater_IsDead_Statics
{
	struct ShoorterCharater_eventIsDead_Parms
	{
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
void Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ShoorterCharater_eventIsDead_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ShoorterCharater_eventIsDead_Parms), &Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShoorterCharater, nullptr, "IsDead", nullptr, nullptr, Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::PropPointers), sizeof(Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::ShoorterCharater_eventIsDead_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::ShoorterCharater_eventIsDead_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AShoorterCharater_IsDead()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShoorterCharater_IsDead_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShoorterCharater::execIsDead)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->IsDead();
	P_NATIVE_END;
}
// End Class AShoorterCharater Function IsDead

// Begin Class AShoorterCharater
void AShoorterCharater::StaticRegisterNativesAShoorterCharater()
{
	UClass* Class = AShoorterCharater::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "EnableMovement", &AShoorterCharater::execEnableMovement },
		{ "IsDead", &AShoorterCharater::execIsDead },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AShoorterCharater);
UClass* Z_Construct_UClass_AShoorterCharater_NoRegister()
{
	return AShoorterCharater::StaticClass();
}
struct Z_Construct_UClass_AShoorterCharater_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "ShoorterCharater.h" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "Category", "MySettings" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitMontage_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationRate_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GunClass_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gun_MetaData[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitMontage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GunClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Gun;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AShoorterCharater_EnableMovement, "EnableMovement" }, // 4208461270
		{ &Z_Construct_UFunction_AShoorterCharater_IsDead, "IsDead" }, // 1386243381
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShoorterCharater>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HitMontage = { "HitMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, HitMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitMontage_MetaData), NewProp_HitMontage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_RotationRate = { "RotationRate", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, RotationRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationRate_MetaData), NewProp_RotationRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_GunClass = { "GunClass", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, GunClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AGun_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GunClass_MetaData), NewProp_GunClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Gun = { "Gun", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, Gun), Z_Construct_UClass_AGun_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gun_MetaData), NewProp_Gun_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShoorterCharater_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HitMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_RotationRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_GunClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Gun,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShoorterCharater_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AShoorterCharater_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_ACharacter,
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShoorterCharater_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AShoorterCharater_Statics::ClassParams = {
	&AShoorterCharater::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AShoorterCharater_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AShoorterCharater_Statics::PropPointers),
	0,
	0x009000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShoorterCharater_Statics::Class_MetaDataParams), Z_Construct_UClass_AShoorterCharater_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AShoorterCharater()
{
	if (!Z_Registration_Info_UClass_AShoorterCharater.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AShoorterCharater.OuterSingleton, Z_Construct_UClass_AShoorterCharater_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AShoorterCharater.OuterSingleton;
}
template<> SIMPLESHOOTER_API UClass* StaticClass<AShoorterCharater>()
{
	return AShoorterCharater::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AShoorterCharater);
AShoorterCharater::~AShoorterCharater() {}
// End Class AShoorterCharater

// Begin Registration
struct Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AShoorterCharater, AShoorterCharater::StaticClass, TEXT("AShoorterCharater"), &Z_Registration_Info_UClass_AShoorterCharater, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AShoorterCharater), 2504016448U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_180662902(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
