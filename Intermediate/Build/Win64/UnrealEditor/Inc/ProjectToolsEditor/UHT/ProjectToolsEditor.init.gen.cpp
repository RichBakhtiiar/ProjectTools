// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProjectToolsEditor_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_ProjectToolsEditor;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_ProjectToolsEditor()
	{
		if (!Z_Registration_Info_UPackage__Script_ProjectToolsEditor.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProjectToolsEditor",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000040,
				0xE3D2F199,
				0x04776ECB,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_ProjectToolsEditor.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_ProjectToolsEditor.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_ProjectToolsEditor(Z_Construct_UPackage__Script_ProjectToolsEditor, TEXT("/Script/ProjectToolsEditor"), Z_Registration_Info_UPackage__Script_ProjectToolsEditor, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xE3D2F199, 0x04776ECB));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
