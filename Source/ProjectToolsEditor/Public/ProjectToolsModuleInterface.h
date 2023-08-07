// Copyright Bakhtiiar Akhmednov IE. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class IProjectToolsModuleListenerInterface
{
public:
	virtual void OnStartupModule() {};
	virtual void OnShutdownModule() {};
};

class IProjectToolsModuleInterface : public IModuleInterface
{
public:
	virtual void StartupModule() override
	{
		if (!IsRunningCommandlet())
		{
			AddModuleListeners();

			for (const TSharedRef<IProjectToolsModuleListenerInterface> ModuleListener : ModuleListeners)
			{
				ModuleListener->OnStartupModule();
			}
		}
	}

	virtual void ShutdownModule() override
	{
		for (const TSharedRef<IProjectToolsModuleListenerInterface> ModuleListener : ModuleListeners)
		{
			ModuleListener->OnShutdownModule();
		}
	}

	virtual void AddModuleListeners() {};

protected:
	TArray<TSharedRef<IProjectToolsModuleListenerInterface>> ModuleListeners;
};
