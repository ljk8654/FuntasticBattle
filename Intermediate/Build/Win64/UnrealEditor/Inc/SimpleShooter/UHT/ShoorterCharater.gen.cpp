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
SIMPLESHOOTER_API UClass* Z_Construct_UClass_ABomb_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AGun_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AHeart_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AMeleeWeapon_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShoorterCharater();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShoorterCharater_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_Atestactor_NoRegister();
SIMPLESHOOTER_API UEnum* Z_Construct_UEnum_SimpleShooter_ECharState();
UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References

// Begin Enum ECharState
static FEnumRegistrationInfo Z_Registration_Info_UEnum_ECharState;
static UEnum* ECharState_StaticEnum()
{
	if (!Z_Registration_Info_UEnum_ECharState.OuterSingleton)
	{
		Z_Registration_Info_UEnum_ECharState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SimpleShooter_ECharState, (UObject*)Z_Construct_UPackage__Script_SimpleShooter(), TEXT("ECharState"));
	}
	return Z_Registration_Info_UEnum_ECharState.OuterSingleton;
}
template<> SIMPLESHOOTER_API UEnum* StaticEnum<ECharState>()
{
	return ECharState_StaticEnum();
}
struct Z_Construct_UEnum_SimpleShooter_ECharState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Hit.DisplayName", "Hit" },
		{ "Hit.Name", "ECharState::Hit" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
		{ "Normal.DisplayName", "Normal" },
		{ "Normal.Name", "ECharState::Normal" },
		{ "Recover.DisplayName", "Recover" },
		{ "Recover.Name", "ECharState::Recover" },
		{ "Stunned.DisplayName", "Stunned" },
		{ "Stunned.Name", "ECharState::Stunned" },
	};
#endif // WITH_METADATA
	static constexpr UECodeGen_Private::FEnumeratorParam Enumerators[] = {
		{ "ECharState::Normal", (int64)ECharState::Normal },
		{ "ECharState::Hit", (int64)ECharState::Hit },
		{ "ECharState::Stunned", (int64)ECharState::Stunned },
		{ "ECharState::Recover", (int64)ECharState::Recover },
	};
	static const UECodeGen_Private::FEnumParams EnumParams;
};
const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SimpleShooter_ECharState_Statics::EnumParams = {
	(UObject*(*)())Z_Construct_UPackage__Script_SimpleShooter,
	nullptr,
	"ECharState",
	"ECharState",
	Z_Construct_UEnum_SimpleShooter_ECharState_Statics::Enumerators,
	RF_Public|RF_Transient|RF_MarkAsNative,
	UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleShooter_ECharState_Statics::Enumerators),
	EEnumFlags::None,
	(uint8)UEnum::ECppForm::EnumClass,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_SimpleShooter_ECharState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_SimpleShooter_ECharState_Statics::Enum_MetaDataParams)
};
UEnum* Z_Construct_UEnum_SimpleShooter_ECharState()
{
	if (!Z_Registration_Info_UEnum_ECharState.InnerSingleton)
	{
		UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ECharState.InnerSingleton, Z_Construct_UEnum_SimpleShooter_ECharState_Statics::EnumParams);
	}
	return Z_Registration_Info_UEnum_ECharState.InnerSingleton;
}
// End Enum ECharState

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

// Begin Class AShoorterCharater Function EnterRagdoll
struct Z_Construct_UFunction_AShoorterCharater_EnterRagdoll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShoorterCharater_EnterRagdoll_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShoorterCharater, nullptr, "EnterRagdoll", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_EnterRagdoll_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShoorterCharater_EnterRagdoll_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AShoorterCharater_EnterRagdoll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShoorterCharater_EnterRagdoll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShoorterCharater::execEnterRagdoll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->EnterRagdoll();
	P_NATIVE_END;
}
// End Class AShoorterCharater Function EnterRagdoll

// Begin Class AShoorterCharater Function ExitRagdoll
struct Z_Construct_UFunction_AShoorterCharater_ExitRagdoll_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShoorterCharater_ExitRagdoll_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShoorterCharater, nullptr, "ExitRagdoll", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_ExitRagdoll_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShoorterCharater_ExitRagdoll_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AShoorterCharater_ExitRagdoll()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShoorterCharater_ExitRagdoll_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShoorterCharater::execExitRagdoll)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ExitRagdoll();
	P_NATIVE_END;
}
// End Class AShoorterCharater Function ExitRagdoll

// Begin Class AShoorterCharater Function Heal
struct Z_Construct_UFunction_AShoorterCharater_Heal_Statics
{
	struct ShoorterCharater_eventHeal_Parms
	{
		float Amount;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "MySettings" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Amount;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AShoorterCharater_Heal_Statics::NewProp_Amount = { "Amount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShoorterCharater_eventHeal_Parms, Amount), METADATA_PARAMS(0, nullptr) };
void Z_Construct_UFunction_AShoorterCharater_Heal_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((ShoorterCharater_eventHeal_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AShoorterCharater_Heal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ShoorterCharater_eventHeal_Parms), &Z_Construct_UFunction_AShoorterCharater_Heal_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShoorterCharater_Heal_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShoorterCharater_Heal_Statics::NewProp_Amount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShoorterCharater_Heal_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_Heal_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShoorterCharater_Heal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShoorterCharater, nullptr, "Heal", nullptr, nullptr, Z_Construct_UFunction_AShoorterCharater_Heal_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_Heal_Statics::PropPointers), sizeof(Z_Construct_UFunction_AShoorterCharater_Heal_Statics::ShoorterCharater_eventHeal_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_Heal_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShoorterCharater_Heal_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AShoorterCharater_Heal_Statics::ShoorterCharater_eventHeal_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AShoorterCharater_Heal()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShoorterCharater_Heal_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShoorterCharater::execHeal)
{
	P_GET_PROPERTY(FFloatProperty,Z_Param_Amount);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->Heal(Z_Param_Amount);
	P_NATIVE_END;
}
// End Class AShoorterCharater Function Heal

// Begin Class AShoorterCharater Function HealthPercent
struct Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics
{
	struct ShoorterCharater_eventHealthPercent_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShoorterCharater_eventHealthPercent_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShoorterCharater, nullptr, "HealthPercent", nullptr, nullptr, Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::PropPointers), sizeof(Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::ShoorterCharater_eventHealthPercent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::ShoorterCharater_eventHealthPercent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AShoorterCharater_HealthPercent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShoorterCharater_HealthPercent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShoorterCharater::execHealthPercent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->HealthPercent();
	P_NATIVE_END;
}
// End Class AShoorterCharater Function HealthPercent

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

// Begin Class AShoorterCharater Function StaminaPercent
struct Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics
{
	struct ShoorterCharater_eventStaminaPercent_Parms
	{
		float ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShoorterCharater_eventStaminaPercent_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShoorterCharater, nullptr, "StaminaPercent", nullptr, nullptr, Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::PropPointers), sizeof(Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::ShoorterCharater_eventStaminaPercent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::ShoorterCharater_eventStaminaPercent_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AShoorterCharater_StaminaPercent()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShoorterCharater_StaminaPercent_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShoorterCharater::execStaminaPercent)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(float*)Z_Param__Result=P_THIS->StaminaPercent();
	P_NATIVE_END;
}
// End Class AShoorterCharater Function StaminaPercent

// Begin Class AShoorterCharater
void AShoorterCharater::StaticRegisterNativesAShoorterCharater()
{
	UClass* Class = AShoorterCharater::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "EnableMovement", &AShoorterCharater::execEnableMovement },
		{ "EnterRagdoll", &AShoorterCharater::execEnterRagdoll },
		{ "ExitRagdoll", &AShoorterCharater::execExitRagdoll },
		{ "Heal", &AShoorterCharater::execHeal },
		{ "HealthPercent", &AShoorterCharater::execHealthPercent },
		{ "IsDead", &AShoorterCharater::execIsDead },
		{ "StaminaPercent", &AShoorterCharater::execStaminaPercent },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentState_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bIsAttacking_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "Category", "MySettings" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Stamina_MetaData[] = {
		{ "Category", "MySettings" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HitMontage_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AttackMontage_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_JumpMontage_MetaData[] = {
		{ "Category", "Combat" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RagdollRecoverTime_MetaData[] = {
		{ "Category", "Stun" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnableDropOnDeath_MetaData[] = {
		{ "Category", "Drop" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeartDropClass_MetaData[] = {
		{ "Category", "Drop" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// NPC BP\xec\x97\x90\xec\x84\x9c\xeb\xa7\x8c true\xeb\xa1\x9c\n" },
#endif
		{ "ModuleRelativePath", "ShoorterCharater.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "NPC BP\xec\x97\x90\xec\x84\x9c\xeb\xa7\x8c true\xeb\xa1\x9c" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeartDropChance_MetaData[] = {
		{ "Category", "Drop" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BombDropClass_MetaData[] = {
		{ "Category", "Drop" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BombDropChance_MetaData[] = {
		{ "Category", "Drop" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDropOnlyOneItem_MetaData[] = {
		{ "Category", "Drop" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDroppedItem_MetaData[] = {
		{ "Category", "Drop" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HeldBomb_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerDamage_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerStunDamage_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_PlayerForce_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RotationRate_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ForwardInput_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RightInput_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MoveForce_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStamina_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxStunGage_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StunDamage_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ChaForce_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_GunClass_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BatClass_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HockeyClass_MetaData[] = {
		{ "Category", "ShoorterCharater" },
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gun_MetaData[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bat_MetaData[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MeleeWeapon_MetaData[] = {
		{ "ModuleRelativePath", "ShoorterCharater.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FBytePropertyParams NewProp_CurrentState_Underlying;
	static const UECodeGen_Private::FEnumPropertyParams NewProp_CurrentState;
	static void NewProp_bIsAttacking_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAttacking;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Stamina;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HitMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_AttackMontage;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_JumpMontage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RagdollRecoverTime;
	static void NewProp_bEnableDropOnDeath_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnableDropOnDeath;
	static const UECodeGen_Private::FClassPropertyParams NewProp_HeartDropClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_HeartDropChance;
	static const UECodeGen_Private::FClassPropertyParams NewProp_BombDropClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_BombDropChance;
	static void NewProp_bDropOnlyOneItem_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDropOnlyOneItem;
	static void NewProp_bDroppedItem_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDroppedItem;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HeldBomb;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerStunDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_PlayerForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RotationRate;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ForwardInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RightInput;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MoveForce;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxStamina;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxStunGage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_StunDamage;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_ChaForce;
	static const UECodeGen_Private::FClassPropertyParams NewProp_GunClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_BatClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_HockeyClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Gun;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Bat;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_MeleeWeapon;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AShoorterCharater_EnableMovement, "EnableMovement" }, // 4208461270
		{ &Z_Construct_UFunction_AShoorterCharater_EnterRagdoll, "EnterRagdoll" }, // 1819184751
		{ &Z_Construct_UFunction_AShoorterCharater_ExitRagdoll, "ExitRagdoll" }, // 3082542266
		{ &Z_Construct_UFunction_AShoorterCharater_Heal, "Heal" }, // 1564785485
		{ &Z_Construct_UFunction_AShoorterCharater_HealthPercent, "HealthPercent" }, // 2728961126
		{ &Z_Construct_UFunction_AShoorterCharater_IsDead, "IsDead" }, // 1386243381
		{ &Z_Construct_UFunction_AShoorterCharater_StaminaPercent, "StaminaPercent" }, // 3147513359
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShoorterCharater>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_CurrentState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_CurrentState = { "CurrentState", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, CurrentState), Z_Construct_UEnum_SimpleShooter_ECharState, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentState_MetaData), NewProp_CurrentState_MetaData) }; // 1499059422
void Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bIsAttacking_SetBit(void* Obj)
{
	((AShoorterCharater*)Obj)->bIsAttacking = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bIsAttacking = { "bIsAttacking", nullptr, (EPropertyFlags)0x0010000000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AShoorterCharater), &Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bIsAttacking_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bIsAttacking_MetaData), NewProp_bIsAttacking_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Stamina = { "Stamina", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, Stamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Stamina_MetaData), NewProp_Stamina_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HitMontage = { "HitMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, HitMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HitMontage_MetaData), NewProp_HitMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_AttackMontage = { "AttackMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, AttackMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AttackMontage_MetaData), NewProp_AttackMontage_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_JumpMontage = { "JumpMontage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, JumpMontage), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_JumpMontage_MetaData), NewProp_JumpMontage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_RagdollRecoverTime = { "RagdollRecoverTime", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, RagdollRecoverTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RagdollRecoverTime_MetaData), NewProp_RagdollRecoverTime_MetaData) };
void Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bEnableDropOnDeath_SetBit(void* Obj)
{
	((AShoorterCharater*)Obj)->bEnableDropOnDeath = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bEnableDropOnDeath = { "bEnableDropOnDeath", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AShoorterCharater), &Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bEnableDropOnDeath_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnableDropOnDeath_MetaData), NewProp_bEnableDropOnDeath_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HeartDropClass = { "HeartDropClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, HeartDropClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AHeart_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeartDropClass_MetaData), NewProp_HeartDropClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HeartDropChance = { "HeartDropChance", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, HeartDropChance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeartDropChance_MetaData), NewProp_HeartDropChance_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_BombDropClass = { "BombDropClass", nullptr, (EPropertyFlags)0x0014000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, BombDropClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ABomb_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BombDropClass_MetaData), NewProp_BombDropClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_BombDropChance = { "BombDropChance", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, BombDropChance), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BombDropChance_MetaData), NewProp_BombDropChance_MetaData) };
void Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bDropOnlyOneItem_SetBit(void* Obj)
{
	((AShoorterCharater*)Obj)->bDropOnlyOneItem = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bDropOnlyOneItem = { "bDropOnlyOneItem", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AShoorterCharater), &Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bDropOnlyOneItem_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDropOnlyOneItem_MetaData), NewProp_bDropOnlyOneItem_MetaData) };
void Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bDroppedItem_SetBit(void* Obj)
{
	((AShoorterCharater*)Obj)->bDroppedItem = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bDroppedItem = { "bDroppedItem", nullptr, (EPropertyFlags)0x0010000000020001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AShoorterCharater), &Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bDroppedItem_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDroppedItem_MetaData), NewProp_bDroppedItem_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HeldBomb = { "HeldBomb", nullptr, (EPropertyFlags)0x0040000000020001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, HeldBomb), Z_Construct_UClass_ABomb_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HeldBomb_MetaData), NewProp_HeldBomb_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_PlayerDamage = { "PlayerDamage", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, PlayerDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerDamage_MetaData), NewProp_PlayerDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_PlayerStunDamage = { "PlayerStunDamage", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, PlayerStunDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerStunDamage_MetaData), NewProp_PlayerStunDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_PlayerForce = { "PlayerForce", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, PlayerForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_PlayerForce_MetaData), NewProp_PlayerForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_RotationRate = { "RotationRate", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, RotationRate), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RotationRate_MetaData), NewProp_RotationRate_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_ForwardInput = { "ForwardInput", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, ForwardInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ForwardInput_MetaData), NewProp_ForwardInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_RightInput = { "RightInput", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, RightInput), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RightInput_MetaData), NewProp_RightInput_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MoveForce = { "MoveForce", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, MoveForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MoveForce_MetaData), NewProp_MoveForce_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MaxStamina = { "MaxStamina", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, MaxStamina), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStamina_MetaData), NewProp_MaxStamina_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MaxStunGage = { "MaxStunGage", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, MaxStunGage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxStunGage_MetaData), NewProp_MaxStunGage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_StunDamage = { "StunDamage", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, StunDamage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StunDamage_MetaData), NewProp_StunDamage_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_ChaForce = { "ChaForce", nullptr, (EPropertyFlags)0x0040000000010001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, ChaForce), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ChaForce_MetaData), NewProp_ChaForce_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_GunClass = { "GunClass", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, GunClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AGun_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_GunClass_MetaData), NewProp_GunClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_BatClass = { "BatClass", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, BatClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AMeleeWeapon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BatClass_MetaData), NewProp_BatClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HockeyClass = { "HockeyClass", nullptr, (EPropertyFlags)0x0044000000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, HockeyClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AMeleeWeapon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HockeyClass_MetaData), NewProp_HockeyClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Gun = { "Gun", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, Gun), Z_Construct_UClass_AGun_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gun_MetaData), NewProp_Gun_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Bat = { "Bat", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, Bat), Z_Construct_UClass_Atestactor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bat_MetaData), NewProp_Bat_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MeleeWeapon = { "MeleeWeapon", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShoorterCharater, MeleeWeapon), Z_Construct_UClass_AMeleeWeapon_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MeleeWeapon_MetaData), NewProp_MeleeWeapon_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShoorterCharater_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_CurrentState_Underlying,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_CurrentState,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bIsAttacking,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Stamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HitMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_AttackMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_JumpMontage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_RagdollRecoverTime,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bEnableDropOnDeath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HeartDropClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HeartDropChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_BombDropClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_BombDropChance,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bDropOnlyOneItem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_bDroppedItem,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HeldBomb,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_PlayerDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_PlayerStunDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_PlayerForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_RotationRate,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_ForwardInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_RightInput,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MoveForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MaxStamina,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MaxStunGage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_StunDamage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_ChaForce,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_GunClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_BatClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_HockeyClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Gun,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_Bat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShoorterCharater_Statics::NewProp_MeleeWeapon,
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
	static constexpr FEnumRegisterCompiledInInfo EnumInfo[] = {
		{ ECharState_StaticEnum, TEXT("ECharState"), &Z_Registration_Info_UEnum_ECharState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1499059422U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AShoorterCharater, AShoorterCharater::StaticClass, TEXT("AShoorterCharater"), &Z_Registration_Info_UClass_AShoorterCharater, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AShoorterCharater), 1968580373U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_2044513764(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_Statics::ClassInfo),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_Statics::EnumInfo));
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
