// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ShooterPlayerController.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLESHOOTER_ShooterPlayerController_generated_h
#error "ShooterPlayerController.generated.h already included, missing '#pragma once' in ShooterPlayerController.h"
#endif
#define SIMPLESHOOTER_ShooterPlayerController_generated_h

#define FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execOnLoginSuccess);


#define FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShooterPlayerController(); \
	friend struct Z_Construct_UClass_AShooterPlayerController_Statics; \
public: \
	DECLARE_CLASS(AShooterPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SimpleShooter"), NO_API) \
	DECLARE_SERIALIZER(AShooterPlayerController)


#define FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShooterPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AShooterPlayerController(AShooterPlayerController&&); \
	AShooterPlayerController(const AShooterPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShooterPlayerController); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShooterPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShooterPlayerController) \
	NO_API virtual ~AShooterPlayerController();


#define FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_14_PROLOG
#define FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_17_INCLASS_NO_PURE_DECLS \
	FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMPLESHOOTER_API UClass* StaticClass<class AShooterPlayerController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FuntasticBattle_Source_SimpleShooter_ShooterPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
