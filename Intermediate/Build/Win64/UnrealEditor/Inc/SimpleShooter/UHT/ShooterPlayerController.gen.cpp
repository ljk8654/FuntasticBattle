// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/ShooterPlayerController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeShooterPlayerController() {}

// Begin Cross Module References
COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_ARemotePlayer_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterPlayerController();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterPlayerController_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_UHUDWidget_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_ULoginWidget_NoRegister();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_ULoomList_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
UPackage* Z_Construct_UPackage__Script_SimpleShooter();
// End Cross Module References

// Begin Class AShooterPlayerController Function OnEnterRoomSuccess
struct Z_Construct_UFunction_AShooterPlayerController_OnEnterRoomSuccess_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShooterPlayerController_OnEnterRoomSuccess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShooterPlayerController, nullptr, "OnEnterRoomSuccess", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnEnterRoomSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShooterPlayerController_OnEnterRoomSuccess_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AShooterPlayerController_OnEnterRoomSuccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShooterPlayerController_OnEnterRoomSuccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShooterPlayerController::execOnEnterRoomSuccess)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnEnterRoomSuccess();
	P_NATIVE_END;
}
// End Class AShooterPlayerController Function OnEnterRoomSuccess

// Begin Class AShooterPlayerController Function OnLoginSuccess
struct Z_Construct_UFunction_AShooterPlayerController_OnLoginSuccess_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShooterPlayerController_OnLoginSuccess_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShooterPlayerController, nullptr, "OnLoginSuccess", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnLoginSuccess_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShooterPlayerController_OnLoginSuccess_Statics::Function_MetaDataParams) };
UFunction* Z_Construct_UFunction_AShooterPlayerController_OnLoginSuccess()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShooterPlayerController_OnLoginSuccess_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShooterPlayerController::execOnLoginSuccess)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnLoginSuccess();
	P_NATIVE_END;
}
// End Class AShooterPlayerController Function OnLoginSuccess

// Begin Class AShooterPlayerController Function OnRemotePlayerEnter
struct Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics
{
	struct ShooterPlayerController_eventOnRemotePlayerEnter_Parms
	{
		int64 PlayerId;
		FVector InitPos;
		float InitYaw;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\x84\xa4\xed\x8a\xb8\xec\x9b\x8c\xed\x81\xac \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8 \xed\x95\xb8\xeb\x93\xa4\xeb\x9f\xac\n" },
#endif
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x84\xa4\xed\x8a\xb8\xec\x9b\x8c\xed\x81\xac \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8 \xed\x95\xb8\xeb\x93\xa4\xeb\x9f\xac" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PlayerId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_InitPos;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_InitYaw;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::NewProp_PlayerId = { "PlayerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShooterPlayerController_eventOnRemotePlayerEnter_Parms, PlayerId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::NewProp_InitPos = { "InitPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShooterPlayerController_eventOnRemotePlayerEnter_Parms, InitPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::NewProp_InitYaw = { "InitYaw", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShooterPlayerController_eventOnRemotePlayerEnter_Parms, InitYaw), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::NewProp_PlayerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::NewProp_InitPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::NewProp_InitYaw,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShooterPlayerController, nullptr, "OnRemotePlayerEnter", nullptr, nullptr, Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::PropPointers), sizeof(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::ShooterPlayerController_eventOnRemotePlayerEnter_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::ShooterPlayerController_eventOnRemotePlayerEnter_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShooterPlayerController::execOnRemotePlayerEnter)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_PlayerId);
	P_GET_STRUCT(FVector,Z_Param_InitPos);
	P_GET_PROPERTY(FFloatProperty,Z_Param_InitYaw);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRemotePlayerEnter(Z_Param_PlayerId,Z_Param_InitPos,Z_Param_InitYaw);
	P_NATIVE_END;
}
// End Class AShooterPlayerController Function OnRemotePlayerEnter

// Begin Class AShooterPlayerController Function OnRemotePlayerLeave
struct Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics
{
	struct ShooterPlayerController_eventOnRemotePlayerLeave_Parms
	{
		int64 PlayerId;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PlayerId;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::NewProp_PlayerId = { "PlayerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShooterPlayerController_eventOnRemotePlayerLeave_Parms, PlayerId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::NewProp_PlayerId,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShooterPlayerController, nullptr, "OnRemotePlayerLeave", nullptr, nullptr, Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::PropPointers), sizeof(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::ShooterPlayerController_eventOnRemotePlayerLeave_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::ShooterPlayerController_eventOnRemotePlayerLeave_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShooterPlayerController::execOnRemotePlayerLeave)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_PlayerId);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRemotePlayerLeave(Z_Param_PlayerId);
	P_NATIVE_END;
}
// End Class AShooterPlayerController Function OnRemotePlayerLeave

// Begin Class AShooterPlayerController Function OnRemotePlayerMove
struct Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics
{
	struct ShooterPlayerController_eventOnRemotePlayerMove_Parms
	{
		int64 PlayerId;
		FVector NewPos;
		float NewYaw;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FInt64PropertyParams NewProp_PlayerId;
	static const UECodeGen_Private::FStructPropertyParams NewProp_NewPos;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_NewYaw;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::NewProp_PlayerId = { "PlayerId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShooterPlayerController_eventOnRemotePlayerMove_Parms, PlayerId), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::NewProp_NewPos = { "NewPos", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShooterPlayerController_eventOnRemotePlayerMove_Parms, NewPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::NewProp_NewYaw = { "NewYaw", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShooterPlayerController_eventOnRemotePlayerMove_Parms, NewYaw), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::NewProp_PlayerId,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::NewProp_NewPos,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::NewProp_NewYaw,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::PropPointers) < 2048);
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AShooterPlayerController, nullptr, "OnRemotePlayerMove", nullptr, nullptr, Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::PropPointers), sizeof(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::ShooterPlayerController_eventOnRemotePlayerMove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00840401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::Function_MetaDataParams), Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::Function_MetaDataParams) };
static_assert(sizeof(Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::ShooterPlayerController_eventOnRemotePlayerMove_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(AShooterPlayerController::execOnRemotePlayerMove)
{
	P_GET_PROPERTY(FInt64Property,Z_Param_PlayerId);
	P_GET_STRUCT(FVector,Z_Param_NewPos);
	P_GET_PROPERTY(FFloatProperty,Z_Param_NewYaw);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->OnRemotePlayerMove(Z_Param_PlayerId,Z_Param_NewPos,Z_Param_NewYaw);
	P_NATIVE_END;
}
// End Class AShooterPlayerController Function OnRemotePlayerMove

// Begin Class AShooterPlayerController
void AShooterPlayerController::StaticRegisterNativesAShooterPlayerController()
{
	UClass* Class = AShooterPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnEnterRoomSuccess", &AShooterPlayerController::execOnEnterRoomSuccess },
		{ "OnLoginSuccess", &AShooterPlayerController::execOnLoginSuccess },
		{ "OnRemotePlayerEnter", &AShooterPlayerController::execOnRemotePlayerEnter },
		{ "OnRemotePlayerLeave", &AShooterPlayerController::execOnRemotePlayerLeave },
		{ "OnRemotePlayerMove", &AShooterPlayerController::execOnRemotePlayerMove },
	};
	FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AShooterPlayerController);
UClass* Z_Construct_UClass_AShooterPlayerController_NoRegister()
{
	return AShooterPlayerController::StaticClass();
}
struct Z_Construct_UClass_AShooterPlayerController_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "ShooterPlayerController.h" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoginWidgetClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomListClass_MetaData[] = {
		{ "Category", "UI" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemotePlayerClass_MetaData[] = {
		{ "Category", "Network" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9b\x90\xea\xb2\xa9 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 BP \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4 (BP_RemotePlayer\xeb\xa5\xbc BP\xec\x97\x90\xec\x84\x9c \xec\xa7\x80\xec\xa0\x95)\n" },
#endif
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\x90\xea\xb2\xa9 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 BP \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4 (BP_RemotePlayer\xeb\xa5\xbc BP\xec\x97\x90\xec\x84\x9c \xec\xa7\x80\xec\xa0\x95)" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLoginWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_WinnerScreenClass_MetaData[] = {
		{ "Category", "ShooterPlayerController" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LoseScreenClass_MetaData[] = {
		{ "Category", "ShooterPlayerController" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RestartDelay_MetaData[] = {
		{ "Category", "ShooterPlayerController" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUD_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RoomList_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RemotePlayers_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9b\x90\xea\xb2\xa9 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xeb\xa7\xb5\n" },
#endif
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9b\x90\xea\xb2\xa9 \xed\x94\x8c\xeb\xa0\x88\xec\x9d\xb4\xec\x96\xb4 \xeb\xa7\xb5" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_HUDClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_LoginWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_RoomListClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_RemotePlayerClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentLoginWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WinnerScreenClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_LoseScreenClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RestartDelay;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HUD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RoomList;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RemotePlayers_ValueProp;
	static const UECodeGen_Private::FInt64PropertyParams NewProp_RemotePlayers_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_RemotePlayers;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AShooterPlayerController_OnEnterRoomSuccess, "OnEnterRoomSuccess" }, // 3933399492
		{ &Z_Construct_UFunction_AShooterPlayerController_OnLoginSuccess, "OnLoginSuccess" }, // 519236268
		{ &Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerEnter, "OnRemotePlayerEnter" }, // 2026872459
		{ &Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerLeave, "OnRemotePlayerLeave" }, // 751292196
		{ &Z_Construct_UFunction_AShooterPlayerController_OnRemotePlayerMove, "OnRemotePlayerMove" }, // 2644595290
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooterPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_HUDClass = { "HUDClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, HUDClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UHUDWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDClass_MetaData), NewProp_HUDClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_LoginWidgetClass = { "LoginWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, LoginWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULoginWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginWidgetClass_MetaData), NewProp_LoginWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RoomListClass = { "RoomListClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, RoomListClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULoomList_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomListClass_MetaData), NewProp_RoomListClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RemotePlayerClass = { "RemotePlayerClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, RemotePlayerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ARemotePlayer_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemotePlayerClass_MetaData), NewProp_RemotePlayerClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_CurrentLoginWidget = { "CurrentLoginWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, CurrentLoginWidget), Z_Construct_UClass_ULoginWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLoginWidget_MetaData), NewProp_CurrentLoginWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_WinnerScreenClass = { "WinnerScreenClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, WinnerScreenClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WinnerScreenClass_MetaData), NewProp_WinnerScreenClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_LoseScreenClass = { "LoseScreenClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, LoseScreenClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoseScreenClass_MetaData), NewProp_LoseScreenClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RestartDelay = { "RestartDelay", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, RestartDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RestartDelay_MetaData), NewProp_RestartDelay_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_HUD = { "HUD", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, HUD), Z_Construct_UClass_UHUDWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUD_MetaData), NewProp_HUD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RoomList = { "RoomList", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, RoomList), Z_Construct_UClass_ULoomList_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomList_MetaData), NewProp_RoomList_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RemotePlayers_ValueProp = { "RemotePlayers", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_ARemotePlayer_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FInt64PropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RemotePlayers_Key_KeyProp = { "RemotePlayers_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RemotePlayers = { "RemotePlayers", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, RemotePlayers), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RemotePlayers_MetaData), NewProp_RemotePlayers_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShooterPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_HUDClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_LoginWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RoomListClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RemotePlayerClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_CurrentLoginWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_WinnerScreenClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_LoseScreenClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RestartDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_HUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RoomList,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RemotePlayers_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RemotePlayers_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RemotePlayers,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterPlayerController_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AShooterPlayerController_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_APlayerController,
	(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterPlayerController_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AShooterPlayerController_Statics::ClassParams = {
	&AShooterPlayerController::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_AShooterPlayerController_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_AShooterPlayerController_Statics::PropPointers),
	0,
	0x009002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AShooterPlayerController_Statics::Class_MetaDataParams), Z_Construct_UClass_AShooterPlayerController_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AShooterPlayerController()
{
	if (!Z_Registration_Info_UClass_AShooterPlayerController.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AShooterPlayerController.OuterSingleton, Z_Construct_UClass_AShooterPlayerController_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AShooterPlayerController.OuterSingleton;
}
template<> SIMPLESHOOTER_API UClass* StaticClass<AShooterPlayerController>()
{
	return AShooterPlayerController::StaticClass();
}
AShooterPlayerController::AShooterPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(AShooterPlayerController);
AShooterPlayerController::~AShooterPlayerController() {}
// End Class AShooterPlayerController

// Begin Registration
struct Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AShooterPlayerController, AShooterPlayerController::StaticClass, TEXT("AShooterPlayerController"), &Z_Registration_Info_UClass_AShooterPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AShooterPlayerController), 3257851932U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_1965430559(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
