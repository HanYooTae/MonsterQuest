// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MonsterQuest/MonsterQuestGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMonsterQuestGameModeBase() {}
// Cross Module References
	MONSTERQUEST_API UClass* Z_Construct_UClass_AMonsterQuestGameModeBase_NoRegister();
	MONSTERQUEST_API UClass* Z_Construct_UClass_AMonsterQuestGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MonsterQuest();
// End Cross Module References
	void AMonsterQuestGameModeBase::StaticRegisterNativesAMonsterQuestGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AMonsterQuestGameModeBase_NoRegister()
	{
		return AMonsterQuestGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AMonsterQuestGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMonsterQuestGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MonsterQuest,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMonsterQuestGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MonsterQuestGameModeBase.h" },
		{ "ModuleRelativePath", "MonsterQuestGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMonsterQuestGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMonsterQuestGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMonsterQuestGameModeBase_Statics::ClassParams = {
		&AMonsterQuestGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMonsterQuestGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMonsterQuestGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMonsterQuestGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMonsterQuestGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMonsterQuestGameModeBase, 1462662786);
	template<> MONSTERQUEST_API UClass* StaticClass<AMonsterQuestGameModeBase>()
	{
		return AMonsterQuestGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMonsterQuestGameModeBase(Z_Construct_UClass_AMonsterQuestGameModeBase, &AMonsterQuestGameModeBase::StaticClass, TEXT("/Script/MonsterQuest"), TEXT("AMonsterQuestGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMonsterQuestGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
