// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ShoorterCharater.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLESHOOTER_ShoorterCharater_generated_h
#error "ShoorterCharater.generated.h already included, missing '#pragma once' in ShoorterCharater.h"
#endif
#define SIMPLESHOOTER_ShoorterCharater_generated_h

#define FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execIsDead); \
	DECLARE_FUNCTION(execEnableMovement);


#define FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShoorterCharater(); \
	friend struct Z_Construct_UClass_AShoorterCharater_Statics; \
public: \
	DECLARE_CLASS(AShoorterCharater, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SimpleShooter"), NO_API) \
	DECLARE_SERIALIZER(AShoorterCharater)


#define FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	AShoorterCharater(AShoorterCharater&&); \
	AShoorterCharater(const AShoorterCharater&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShoorterCharater); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShoorterCharater); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShoorterCharater) \
	NO_API virtual ~AShoorterCharater();


#define FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_11_PROLOG
#define FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_14_INCLASS_NO_PURE_DECLS \
	FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMPLESHOOTER_API UClass* StaticClass<class AShoorterCharater>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_FuntasticBattle_Source_SimpleShooter_ShoorterCharater_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
