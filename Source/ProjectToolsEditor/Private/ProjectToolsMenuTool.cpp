// Copyright Bakhtiiar Akhmednov IE. All Rights Reserved.

#include "ProjectToolsMenuTool.h"
#include "Framework/Commands/Commands.h"
#include "EditorStyleSet.h"
#include "ProjectToolsEditor.h"
#include "ProjectToolsEditorSubsystem.h"
#include "Framework/Commands/UICommandInfo.h"
#include "Framework/Commands/InputChord.h"

#define LOCTEXT_NAMESPACE "ProjectToolsMenuTool"

class MenuToolCommands : public TCommands<MenuToolCommands>
{
public:
	MenuToolCommands()
		: TCommands<MenuToolCommands>(
			TEXT("MenuTool"), // Context name for fast lookup
			FText::FromString("AvadaKedavra Menu tool"), // Context name for displaying
			NAME_None, // No parent context
			FEditorStyle::GetStyleSetName() // Icon Style Set
		)
	{
	}

	virtual void RegisterCommands() override
	{
		UI_COMMAND(SetupLightingContentCommand, "Setup Lighting Content",
		           "Adds a Lighting folder with its own objects inside: Exponential Height Fog, Light Source, PostProcessVolume, Sky Sphere, SkyLight and others specified in the editor settings.",
		           EUserInterfaceActionType::Button,
		           FInputChord());

		UI_COMMAND(AutoSetupFolderCommand, "Auto Setup Folder",
		           "Sorts objects into folders using prefixes. Can be configured in the editor settings.",
		           EUserInterfaceActionType::Button,
		           FInputChord());

		UI_COMMAND(AutoSetupPackCommand, "Auto Setup Pack",
		           "Moves objects without a prefix to the specified folder. Folder can be configured in the editor settings.",
		           EUserInterfaceActionType::Button,
		           FInputChord());

		UI_COMMAND(SetupAffectDistanceFieldLighting, "Setup Affect Distance Field Lighting",
					"Set affect distance field lighting to true or false",
					EUserInterfaceActionType::Button,
					FInputChord());
	}

public:
	TSharedPtr<FUICommandInfo> SetupLightingContentCommand;
	TSharedPtr<FUICommandInfo> AutoSetupFolderCommand;
	TSharedPtr<FUICommandInfo> AutoSetupPackCommand;
	TSharedPtr<FUICommandInfo> SetupAffectDistanceFieldLighting;
};

void ProjectToolsMenuTool::OnStartupModule()
{
	CommandList = MakeShareable(new FUICommandList);
	MenuToolCommands::Register();
	MapCommands();
	FProjectToolsEditorModule::Get().AddMenuExtension(
		FMenuExtensionDelegate::CreateRaw(this, &ProjectToolsMenuTool::MakeMenuEntry),
		FName("ProjectToolsToolsSeparator"),
		CommandList, EExtensionHook::Before);

	IProjectToolsModuleListenerInterface::OnStartupModule();
}

void ProjectToolsMenuTool::OnShutdownModule()
{
	MenuToolCommands::Unregister();

	IProjectToolsModuleListenerInterface::OnShutdownModule();
}

void ProjectToolsMenuTool::MakeMenuEntry(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.AddMenuEntry(MenuToolCommands::Get().SetupLightingContentCommand);
	MenuBuilder.AddMenuEntry(MenuToolCommands::Get().AutoSetupFolderCommand);
	MenuBuilder.AddMenuEntry(MenuToolCommands::Get().AutoSetupPackCommand);
	MenuBuilder.AddMenuEntry(MenuToolCommands::Get().SetupAffectDistanceFieldLighting);
}

void ProjectToolsMenuTool::MapCommands()
{
	const auto& Commands = MenuToolCommands::Get();

	CommandList->MapAction(
		Commands.SetupLightingContentCommand,
		FExecuteAction::CreateSP(this, &ProjectToolsMenuTool::SetupLightingContentClicked),
		FCanExecuteAction());

	CommandList->MapAction(
		Commands.AutoSetupFolderCommand,
		FExecuteAction::CreateSP(this, &ProjectToolsMenuTool::AutoSetupFolderClicked),
		FCanExecuteAction());

	CommandList->MapAction(
		Commands.AutoSetupPackCommand,
		FExecuteAction::CreateSP(this, &ProjectToolsMenuTool::AutoSetupPackClicked),
		FCanExecuteAction());

	CommandList->MapAction(
		Commands.SetupAffectDistanceFieldLighting,
		FExecuteAction::CreateSP(this, &ProjectToolsMenuTool::SetupAffectDistanceFieldLightingClicked),
		FCanExecuteAction());
}

void ProjectToolsMenuTool::SetupLightingContentClicked()
{
	UProjectToolsEditorSubsystem* Subsystem = GEditor->GetEditorSubsystem<UProjectToolsEditorSubsystem>();
	if (!Subsystem)
	{
		return;
	}

	Subsystem->SetupLightingContent();
}

void ProjectToolsMenuTool::AutoSetupFolderClicked()
{
	UProjectToolsEditorSubsystem* Subsystem = GEditor->GetEditorSubsystem<UProjectToolsEditorSubsystem>();
	if (!Subsystem)
	{
		return;
	}

	Subsystem->AutoSetupFolders();
}

void ProjectToolsMenuTool::AutoSetupPackClicked()
{
	UProjectToolsEditorSubsystem* Subsystem = GEditor->GetEditorSubsystem<UProjectToolsEditorSubsystem>();
	if (!Subsystem)
	{
		return;
	}

	Subsystem->AutoSetupPack();
}

void ProjectToolsMenuTool::SetupAffectDistanceFieldLightingClicked()
{
	UProjectToolsEditorSubsystem* Subsystem = GEditor->GetEditorSubsystem<UProjectToolsEditorSubsystem>();
	if (!Subsystem)
	{
		return;
	}

	Subsystem->SetupAffectDistanceFieldLighting();
}

#undef LOCTEXT_NAMESPACE
