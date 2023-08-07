// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProjectToolsEditor/Public/ProjectToolsEditorSubsystem.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectToolsEditorSubsystem() {}
// Cross Module References
	EDITORSUBSYSTEM_API UClass* Z_Construct_UClass_UEditorSubsystem();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	PROJECTTOOLSEDITOR_API UClass* Z_Construct_UClass_UProjectToolsEditorSubsystem();
	PROJECTTOOLSEDITOR_API UClass* Z_Construct_UClass_UProjectToolsEditorSubsystem_NoRegister();
	UPackage* Z_Construct_UPackage__Script_ProjectToolsEditor();
// End Cross Module References
	DEFINE_FUNCTION(UProjectToolsEditorSubsystem::execSetupAffectDistanceFieldLighting)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetupAffectDistanceFieldLighting();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UProjectToolsEditorSubsystem::execAutoSetupPack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AutoSetupPack();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UProjectToolsEditorSubsystem::execAutoSetupFolders)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AutoSetupFolders();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UProjectToolsEditorSubsystem::execSetupLightingContent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetupLightingContent();
		P_NATIVE_END;
	}
	void UProjectToolsEditorSubsystem::StaticRegisterNativesUProjectToolsEditorSubsystem()
	{
		UClass* Class = UProjectToolsEditorSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AutoSetupFolders", &UProjectToolsEditorSubsystem::execAutoSetupFolders },
			{ "AutoSetupPack", &UProjectToolsEditorSubsystem::execAutoSetupPack },
			{ "SetupAffectDistanceFieldLighting", &UProjectToolsEditorSubsystem::execSetupAffectDistanceFieldLighting },
			{ "SetupLightingContent", &UProjectToolsEditorSubsystem::execSetupLightingContent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupFolders_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupFolders_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProjectTools Tools | ProjectTools Editor Subsystem" },
		{ "Comment", "// Sorts objects into folders using prefixes. Can be configured in the editor settings.\n" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
		{ "ToolTip", "Sorts objects into folders using prefixes. Can be configured in the editor settings." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupFolders_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProjectToolsEditorSubsystem, nullptr, "AutoSetupFolders", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupFolders_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupFolders_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupFolders()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupFolders_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupPack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupPack_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProjectTools Tools | ProjectTools Editor Subsystem" },
		{ "Comment", "// Moves objects without a prefix to the specified folder. Folder can be configured in the editor settings.\n" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
		{ "ToolTip", "Moves objects without a prefix to the specified folder. Folder can be configured in the editor settings." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupPack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProjectToolsEditorSubsystem, nullptr, "AutoSetupPack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupPack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupPack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupPack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupPack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupAffectDistanceFieldLighting_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupAffectDistanceFieldLighting_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProjectTools Tools | ProjectTools Editor Subsystem" },
		{ "Comment", "// Sets boolean Affect Distance Field Lighting to true / false\n" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
		{ "ToolTip", "Sets boolean Affect Distance Field Lighting to true / false" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupAffectDistanceFieldLighting_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProjectToolsEditorSubsystem, nullptr, "SetupAffectDistanceFieldLighting", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupAffectDistanceFieldLighting_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupAffectDistanceFieldLighting_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupAffectDistanceFieldLighting()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupAffectDistanceFieldLighting_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupLightingContent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupLightingContent_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProjectTools Tools | ProjectTools Editor Subsystem" },
		{ "Comment", "// Adds a Lighting folder with its own objects inside: Atmospheric Fog, Light Source, PostProcessVolume, Sky Sphere, SkyLight and others specified in the editor settings\n" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
		{ "ToolTip", "Adds a Lighting folder with its own objects inside: Atmospheric Fog, Light Source, PostProcessVolume, Sky Sphere, SkyLight and others specified in the editor settings" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupLightingContent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UProjectToolsEditorSubsystem, nullptr, "SetupLightingContent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupLightingContent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupLightingContent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupLightingContent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupLightingContent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UProjectToolsEditorSubsystem);
	UClass* Z_Construct_UClass_UProjectToolsEditorSubsystem_NoRegister()
	{
		return UProjectToolsEditorSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_LightingActors_ValueProp;
		static const UECodeGen_Private::FSoftClassPropertyParams NewProp_LightingActors_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LightingActors_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_LightingActors;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AutoSetupFoldersMap_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_AutoSetupFoldersMap_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoSetupFoldersMap_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_AutoSetupFoldersMap;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AutoSetupPackFolderName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AutoSetupPackFolderName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsAffected_MetaData[];
#endif
		static void NewProp_bIsAffected_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsAffected;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEditorSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_ProjectToolsEditor,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupFolders, "AutoSetupFolders" }, // 1311957440
		{ &Z_Construct_UFunction_UProjectToolsEditorSubsystem_AutoSetupPack, "AutoSetupPack" }, // 2467085952
		{ &Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupAffectDistanceFieldLighting, "SetupAffectDistanceFieldLighting" }, // 2994426656
		{ &Z_Construct_UFunction_UProjectToolsEditorSubsystem_SetupLightingContent, "SetupLightingContent" }, // 3278683590
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::Class_MetaDataParams[] = {
		{ "DisplayName", "ProjectTools Editor Subsystem" },
		{ "IncludePath", "ProjectToolsEditorSubsystem.h" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors_ValueProp = { "LightingActors", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors_Key_KeyProp = { "LightingActors_Key", nullptr, (EPropertyFlags)0x0004000000004001, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors_MetaData[] = {
		{ "Category", "Setup Lighting Content" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors = { "LightingActors", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UProjectToolsEditorSubsystem, LightingActors), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap_ValueProp = { "AutoSetupFoldersMap", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap_Key_KeyProp = { "AutoSetupFoldersMap_Key", nullptr, (EPropertyFlags)0x0000000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap_MetaData[] = {
		{ "Category", "Auto Setup Folder" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap = { "AutoSetupFoldersMap", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UProjectToolsEditorSubsystem, AutoSetupFoldersMap), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupPackFolderName_MetaData[] = {
		{ "Category", "Auto Setup Pack" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupPackFolderName = { "AutoSetupPackFolderName", nullptr, (EPropertyFlags)0x0010000000004005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(UProjectToolsEditorSubsystem, AutoSetupPackFolderName), METADATA_PARAMS(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupPackFolderName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupPackFolderName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_bIsAffected_MetaData[] = {
		{ "Category", "Setup Affect Distance Field Lighting" },
		{ "ModuleRelativePath", "Public/ProjectToolsEditorSubsystem.h" },
	};
#endif
	void Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_bIsAffected_SetBit(void* Obj)
	{
		((UProjectToolsEditorSubsystem*)Obj)->bIsAffected = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_bIsAffected = { "bIsAffected", nullptr, (EPropertyFlags)0x0010000000014005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(UProjectToolsEditorSubsystem), &Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_bIsAffected_SetBit, METADATA_PARAMS(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_bIsAffected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_bIsAffected_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_LightingActors,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupFoldersMap,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_AutoSetupPackFolderName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::NewProp_bIsAffected,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UProjectToolsEditorSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::ClassParams = {
		&UProjectToolsEditorSubsystem::StaticClass,
		"Editor",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::PropPointers),
		0,
		0x001000A6u,
		METADATA_PARAMS(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UProjectToolsEditorSubsystem()
	{
		if (!Z_Registration_Info_UClass_UProjectToolsEditorSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UProjectToolsEditorSubsystem.OuterSingleton, Z_Construct_UClass_UProjectToolsEditorSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UProjectToolsEditorSubsystem.OuterSingleton;
	}
	template<> PROJECTTOOLSEDITOR_API UClass* StaticClass<UProjectToolsEditorSubsystem>()
	{
		return UProjectToolsEditorSubsystem::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UProjectToolsEditorSubsystem);
	UProjectToolsEditorSubsystem::~UProjectToolsEditorSubsystem() {}
	struct Z_CompiledInDeferFile_FID_VP_Inception_Plugins_ProjectTools_Source_ProjectToolsEditor_Public_ProjectToolsEditorSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_VP_Inception_Plugins_ProjectTools_Source_ProjectToolsEditor_Public_ProjectToolsEditorSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UProjectToolsEditorSubsystem, UProjectToolsEditorSubsystem::StaticClass, TEXT("UProjectToolsEditorSubsystem"), &Z_Registration_Info_UClass_UProjectToolsEditorSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UProjectToolsEditorSubsystem), 795205272U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_VP_Inception_Plugins_ProjectTools_Source_ProjectToolsEditor_Public_ProjectToolsEditorSubsystem_h_962119469(TEXT("/Script/ProjectToolsEditor"),
		Z_CompiledInDeferFile_FID_VP_Inception_Plugins_ProjectTools_Source_ProjectToolsEditor_Public_ProjectToolsEditorSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_VP_Inception_Plugins_ProjectTools_Source_ProjectToolsEditor_Public_ProjectToolsEditorSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
