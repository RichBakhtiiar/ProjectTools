// Copyright Bakhtiiar Akhmednov IE. All Rights Reserved.

#pragma once

#include "ProjectToolsModuleInterface.h"
#include "Templates/SharedPointer.h"

class FMenuBuilder;
class FUICommandList;

class ProjectToolsMenuTool : public IProjectToolsModuleListenerInterface, public TSharedFromThis<ProjectToolsMenuTool>
{
public:
    virtual ~ProjectToolsMenuTool() {}

    virtual void OnStartupModule() override;
    virtual void OnShutdownModule() override;

    void MakeMenuEntry(FMenuBuilder& MenuBuilder);

protected:
    TSharedPtr<FUICommandList> CommandList;

    void MapCommands();

    // UI Command functions
    void SetupLightingContentClicked();
    void AutoSetupFolderClicked();
    void AutoSetupPackClicked();
    void SetupAffectDistanceFieldLightingClicked();
};
