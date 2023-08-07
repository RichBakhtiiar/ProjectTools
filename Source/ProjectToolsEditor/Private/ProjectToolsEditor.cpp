// Copyright Bakhtiiar Akhmednov IE. All Rights Reserved.

#include "ProjectToolsEditor.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"
#include "LevelEditor.h"
#include "ProjectToolsMenuTool.h"
#include "ProjectToolsEditorSubsystem.h"
#include "ProjectToolsTypes.h"

#define LOCTEXT_NAMESPACE "FProjectToolsEditorModule"

TSharedRef<FWorkspaceItem> FProjectToolsEditorModule::MenuRoot = FWorkspaceItem::NewGroup(FText::FromString("Menu Root"));

void FProjectToolsEditorModule::StartupModule()
{
	RegisterSettings();

	if (!IsRunningCommandlet())
	{
		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		LevelEditorMenuExtensibilityManager = LevelEditorModule.GetMenuExtensibilityManager();
		MenuExtender = MakeShareable(new FExtender);
		MenuExtender->AddMenuBarExtension(
			"Help",
			EExtensionHook::After,
			nullptr,
			FMenuBarExtensionDelegate::CreateRaw(this, &FProjectToolsEditorModule::MakePullDownMenu));
		LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);
	}

	IProjectToolsModuleInterface::StartupModule();
}

void FProjectToolsEditorModule::ShutdownModule()
{
	UnregisterSettings();

	IProjectToolsModuleInterface::ShutdownModule();
}

void FProjectToolsEditorModule::AddModuleListeners()
{
	ModuleListeners.Add(MakeShareable(new ProjectToolsMenuTool));
}

void FProjectToolsEditorModule::RegisterSettings()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		// Create the new category
		SettingsContainer = SettingsModule->GetContainer("Editor");

		SettingsContainer->DescribeCategory("ProjectTools Tools",
		                                    LOCTEXT("ProjectToolsCategoryName", "ProjectTools Tools"),
		                                    LOCTEXT("ProjectToolsCategoryDescription", "ProjectTools extra functions")
		);

		// Register the settings
		SettingsSection = SettingsModule->RegisterSettings(
			"Editor", "ProjectTools", "ProjectTools Tools",
			LOCTEXT("ProjectToolsSettingsName", "ProjectTools Tools"),
			LOCTEXT("ProjectToolsSettingsDescription", "ProjectTools extra functions"),
			GetMutableDefault<UProjectToolsEditorSubsystem>()
		);

		// Register the save handler to your settings, you might want to use it to
		// validate those or just act to settings changes.
		if (SettingsSection.IsValid())
		{
			SettingsSection->OnModified().BindRaw(this, &FProjectToolsEditorModule::HandleSettingsSaved);
		}

		UE_LOG(LogProjectToolsTools, Log, TEXT("ProjectTools Tools settings registered"));
	}
}

void FProjectToolsEditorModule::UnregisterSettings() const
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Editor", "ProjectTools", "ProjectTools Tools");
		UE_LOG(LogProjectToolsTools, Log, TEXT("ProjectTools Tools settings unregistered"))
	}
}

bool FProjectToolsEditorModule::HandleSettingsSaved() const
{
	//UProjectToolsEditorSubsystem* ProjectToolsEditorSubsystem = GetMutableDefault<UProjectToolsEditorSubsystem>();
	UProjectToolsEditorSubsystem* ProjectToolsEditorSubsystem = GEditor->GetEditorSubsystem<UProjectToolsEditorSubsystem>();
	if (ProjectToolsEditorSubsystem)
	{
		ProjectToolsEditorSubsystem->SaveConfig();
		UE_LOG(LogProjectToolsTools, Log, TEXT("ProjectTools Tools settings saved"));
	}
	else
	{
		UE_LOG(LogProjectToolsTools, Error, TEXT("Can't get UProjectToolsEditorSubsystem while settings saving!"));
	}

	return true;
}

void FProjectToolsEditorModule::AddMenuExtension(const FMenuExtensionDelegate& ExtensionDelegate, FName ExtensionHook,
                                              const TSharedPtr<FUICommandList>& CommandList,
                                              EExtensionHook::Position Position) const
{
	MenuExtender->AddMenuExtension(ExtensionHook, Position, CommandList, ExtensionDelegate);
}

void FProjectToolsEditorModule::MakePullDownMenu(FMenuBarBuilder& MenuBuilder)
{
	MenuBuilder.AddPullDownMenu(
		FText::FromString("ProjectTools"),
		FText::FromString("Open the ProjectTools Tools Menu"),
		FNewMenuDelegate::CreateRaw(this, &FProjectToolsEditorModule::FillPullDownMenu),
		FName("ProjectToolsMenu"),
		FName(TEXT("ProjectToolsMenu"))
	);
}

void FProjectToolsEditorModule::FillPullDownMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection(FName("ProjectToolsaSection"), FText::FromString("ProjectTools Tools"));
	MenuBuilder.AddMenuSeparator(FName("ProjectToolsToolsSeparator"));
	MenuBuilder.EndSection();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FProjectToolsEditorModule, ProjectToolsEditor)
