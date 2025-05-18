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
ENGINE_API UClass* Z_Construct_UClass_APlayerController();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterPlayerController();
SIMPLESHOOTER_API UClass* Z_Construct_UClass_AShooterPlayerController_NoRegister();
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

// Begin Class AShooterPlayerController
void AShooterPlayerController::StaticRegisterNativesAShooterPlayerController()
{
	UClass* Class = AShooterPlayerController::StaticClass();
	static const FNameNativePtrPair Funcs[] = {
		{ "OnEnterRoomSuccess", &AShooterPlayerController::execOnEnterRoomSuccess },
		{ "OnLoginSuccess", &AShooterPlayerController::execOnLoginSuccess },
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
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "ShooterPlayerController.h" },
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
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_CurrentLoginWidget_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ShooterPlayerController.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HUDClass_MetaData[] = {
		{ "Category", "ShooterPlayerController" },
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
#endif // WITH_METADATA
	static const UECodeGen_Private::FClassPropertyParams NewProp_LoginWidgetClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_RoomListClass;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_CurrentLoginWidget;
	static const UECodeGen_Private::FClassPropertyParams NewProp_HUDClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_WinnerScreenClass;
	static const UECodeGen_Private::FClassPropertyParams NewProp_LoseScreenClass;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_RestartDelay;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HUD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RoomList;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AShooterPlayerController_OnEnterRoomSuccess, "OnEnterRoomSuccess" }, // 3933399492
		{ &Z_Construct_UFunction_AShooterPlayerController_OnLoginSuccess, "OnLoginSuccess" }, // 519236268
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AShooterPlayerController>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_LoginWidgetClass = { "LoginWidgetClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, LoginWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULoginWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoginWidgetClass_MetaData), NewProp_LoginWidgetClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RoomListClass = { "RoomListClass", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, RoomListClass), Z_Construct_UClass_UClass, Z_Construct_UClass_ULoomList_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomListClass_MetaData), NewProp_RoomListClass_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_CurrentLoginWidget = { "CurrentLoginWidget", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, CurrentLoginWidget), Z_Construct_UClass_ULoginWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_CurrentLoginWidget_MetaData), NewProp_CurrentLoginWidget_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_HUDClass = { "HUDClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, HUDClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUDClass_MetaData), NewProp_HUDClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_WinnerScreenClass = { "WinnerScreenClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, WinnerScreenClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_WinnerScreenClass_MetaData), NewProp_WinnerScreenClass_MetaData) };
const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_LoseScreenClass = { "LoseScreenClass", nullptr, (EPropertyFlags)0x0044000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, LoseScreenClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LoseScreenClass_MetaData), NewProp_LoseScreenClass_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RestartDelay = { "RestartDelay", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, RestartDelay), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RestartDelay_MetaData), NewProp_RestartDelay_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_HUD = { "HUD", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, HUD), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HUD_MetaData), NewProp_HUD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RoomList = { "RoomList", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AShooterPlayerController, RoomList), Z_Construct_UClass_ULoomList_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RoomList_MetaData), NewProp_RoomList_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AShooterPlayerController_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_LoginWidgetClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RoomListClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_CurrentLoginWidget,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_HUDClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_WinnerScreenClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_LoseScreenClass,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RestartDelay,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_HUD,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AShooterPlayerController_Statics::NewProp_RoomList,
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
		{ Z_Construct_UClass_AShooterPlayerController, AShooterPlayerController::StaticClass, TEXT("AShooterPlayerController"), &Z_Registration_Info_UClass_AShooterPlayerController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AShooterPlayerController), 1516085493U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_2850837028(TEXT("/Script/SimpleShooter"),
	Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
