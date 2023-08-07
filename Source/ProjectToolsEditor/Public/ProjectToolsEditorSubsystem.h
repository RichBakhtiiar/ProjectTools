// Copyright Bakhtiiar Akhmednov IE. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMeshActor.h"
#include "ProjectToolsEditorSubsystem.generated.h"

UCLASS(Config = Editor, DefaultConfig, meta = (DisplayName = "ProjectTools Editor Subsystem"))
class PROJECTTOOLSEDITOR_API UProjectToolsEditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	UProjectToolsEditorSubsystem();

	//=====================================================================================
	// SetupLightingContent
	//=====================================================================================
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Setup Lighting Content")
	TMap<TSoftClassPtr<AActor>, FString> LightingActors;

	// Adds a Lighting folder with its own objects inside: Atmospheric Fog, Light Source, PostProcessVolume, Sky Sphere, SkyLight and others specified in the editor settings
	UFUNCTION(BlueprintCallable, Category = "ProjectTools Tools | ProjectTools Editor Subsystem")
	void SetupLightingContent();

	//=====================================================================================
	// AutoSetupFolders
	//=====================================================================================
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Auto Setup Folder")
	TMap<FString, FString> AutoSetupFoldersMap;

	// Sorts objects into folders using prefixes. Can be configured in the editor settings.
	UFUNCTION(BlueprintCallable, Category = "ProjectTools Tools | ProjectTools Editor Subsystem")
	void AutoSetupFolders();
	
	//=====================================================================================
	// AutoSetupPack
	//=====================================================================================
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Config, Category = "Auto Setup Pack")
	FString AutoSetupPackFolderName;

	// Moves objects without a prefix to the specified folder. Folder can be configured in the editor settings.
	UFUNCTION(BlueprintCallable, Category = "ProjectTools Tools | ProjectTools Editor Subsystem")
	void AutoSetupPack();

	//=====================================================================================
	// SetupAffectDistanceFieldLighting
	//=====================================================================================
public: 
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category = "Setup Affect Distance Field Lighting")
	bool bIsAffected = true;

	// Sets boolean Affect Distance Field Lighting to true / false
	UFUNCTION(BlueprintCallable, Category = "ProjectTools Tools | ProjectTools Editor Subsystem")
	void SetupAffectDistanceFieldLighting();
};
