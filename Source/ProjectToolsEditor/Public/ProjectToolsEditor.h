// Copyright Bakhtiiar Akhmednov IE. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "ProjectToolsModuleInterface.h"

class ISettingsContainer;
class ISettingsSection;

class FProjectToolsEditorModule : public IProjectToolsModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual void AddModuleListeners() override;

	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline FProjectToolsEditorModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FProjectToolsEditorModule>("ProjectToolsEditor");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("ProjectToolsEditor");
	}

	//=====================================================================================
	// Settings extension
	//=====================================================================================
public:
	void RegisterSettings();
	void UnregisterSettings() const;
	bool HandleSettingsSaved() const;

protected:
	TSharedPtr<ISettingsContainer> SettingsContainer;
	TSharedPtr<ISettingsSection> SettingsSection;

	//=====================================================================================
	// Menu extension
	//=====================================================================================
public:
	void AddMenuExtension(const FMenuExtensionDelegate& ExtensionDelegate, FName ExtensionHook, const TSharedPtr<FUICommandList>& CommandList = nullptr, EExtensionHook::Position Position = EExtensionHook::Before) const;
	TSharedRef<FWorkspaceItem> GetMenuRoot() { return MenuRoot; };

protected:
	TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager;
	TSharedPtr<FExtender> MenuExtender;

	static TSharedRef<FWorkspaceItem> MenuRoot;

	void MakePullDownMenu(FMenuBarBuilder& MenuBuilder);
	void FillPullDownMenu(FMenuBuilder& MenuBuilder);
};
