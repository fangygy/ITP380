// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LAB5_lab5Character_generated_h
#error "lab5Character.generated.h already included, missing '#pragma once' in lab5Character.h"
#endif
#define LAB5_lab5Character_generated_h

#define lab5_Source_lab5_lab5Character_h_9_RPC_WRAPPERS
#define lab5_Source_lab5_lab5Character_h_9_RPC_WRAPPERS_NO_PURE_DECLS
#define lab5_Source_lab5_lab5Character_h_9_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAlab5Character(); \
	friend LAB5_API class UClass* Z_Construct_UClass_Alab5Character(); \
	public: \
	DECLARE_CLASS(Alab5Character, ACharacter, COMPILED_IN_FLAGS(0), 0, lab5, NO_API) \
	DECLARE_SERIALIZER(Alab5Character) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<Alab5Character*>(this); }


#define lab5_Source_lab5_lab5Character_h_9_INCLASS \
	private: \
	static void StaticRegisterNativesAlab5Character(); \
	friend LAB5_API class UClass* Z_Construct_UClass_Alab5Character(); \
	public: \
	DECLARE_CLASS(Alab5Character, ACharacter, COMPILED_IN_FLAGS(0), 0, lab5, NO_API) \
	DECLARE_SERIALIZER(Alab5Character) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<Alab5Character*>(this); }


#define lab5_Source_lab5_lab5Character_h_9_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API Alab5Character(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(Alab5Character) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Alab5Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Alab5Character); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API Alab5Character(const Alab5Character& InCopy); \
public:


#define lab5_Source_lab5_lab5Character_h_9_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API Alab5Character(const Alab5Character& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, Alab5Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(Alab5Character); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(Alab5Character)


#define lab5_Source_lab5_lab5Character_h_6_PROLOG
#define lab5_Source_lab5_lab5Character_h_9_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	lab5_Source_lab5_lab5Character_h_9_RPC_WRAPPERS \
	lab5_Source_lab5_lab5Character_h_9_INCLASS \
	lab5_Source_lab5_lab5Character_h_9_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define lab5_Source_lab5_lab5Character_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	lab5_Source_lab5_lab5Character_h_9_RPC_WRAPPERS_NO_PURE_DECLS \
	lab5_Source_lab5_lab5Character_h_9_INCLASS_NO_PURE_DECLS \
	lab5_Source_lab5_lab5Character_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID lab5_Source_lab5_lab5Character_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
