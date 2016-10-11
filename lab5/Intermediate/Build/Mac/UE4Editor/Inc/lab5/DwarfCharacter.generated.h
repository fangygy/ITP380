// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LAB5_DwarfCharacter_generated_h
#error "DwarfCharacter.generated.h already included, missing '#pragma once' in DwarfCharacter.h"
#endif
#define LAB5_DwarfCharacter_generated_h

#define lab5_Source_lab5_DwarfCharacter_h_11_RPC_WRAPPERS
#define lab5_Source_lab5_DwarfCharacter_h_11_RPC_WRAPPERS_NO_PURE_DECLS
#define lab5_Source_lab5_DwarfCharacter_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesADwarfCharacter(); \
	friend LAB5_API class UClass* Z_Construct_UClass_ADwarfCharacter(); \
	public: \
	DECLARE_CLASS(ADwarfCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, lab5, NO_API) \
	DECLARE_SERIALIZER(ADwarfCharacter) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ADwarfCharacter*>(this); }


#define lab5_Source_lab5_DwarfCharacter_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesADwarfCharacter(); \
	friend LAB5_API class UClass* Z_Construct_UClass_ADwarfCharacter(); \
	public: \
	DECLARE_CLASS(ADwarfCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, lab5, NO_API) \
	DECLARE_SERIALIZER(ADwarfCharacter) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC}; \
	virtual UObject* _getUObject() const override { return const_cast<ADwarfCharacter*>(this); }


#define lab5_Source_lab5_DwarfCharacter_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ADwarfCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ADwarfCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADwarfCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADwarfCharacter); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ADwarfCharacter(const ADwarfCharacter& InCopy); \
public:


#define lab5_Source_lab5_DwarfCharacter_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API ADwarfCharacter(const ADwarfCharacter& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ADwarfCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ADwarfCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ADwarfCharacter)


#define lab5_Source_lab5_DwarfCharacter_h_8_PROLOG
#define lab5_Source_lab5_DwarfCharacter_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	lab5_Source_lab5_DwarfCharacter_h_11_RPC_WRAPPERS \
	lab5_Source_lab5_DwarfCharacter_h_11_INCLASS \
	lab5_Source_lab5_DwarfCharacter_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define lab5_Source_lab5_DwarfCharacter_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	lab5_Source_lab5_DwarfCharacter_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	lab5_Source_lab5_DwarfCharacter_h_11_INCLASS_NO_PURE_DECLS \
	lab5_Source_lab5_DwarfCharacter_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID lab5_Source_lab5_DwarfCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
