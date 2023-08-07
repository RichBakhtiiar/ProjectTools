// Copyright Bakhtiiar Akhmednov IE. All Rights Reserved.

#include "ProjectToolsEditorSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Subsystems/EditorActorSubsystem.h"

#include "Engine/ExponentialHeightFog.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Engine/DirectionalLight.h"
#include "Components/DirectionalLightComponent.h"
#include "Engine/PostProcessVolume.h"
#include "Components/SkyAtmosphereComponent.h"
#include "Engine/SkyLight.h"
#include "Components/SkyLightComponent.h"
#include "UObject/ConstructorHelpers.h"

#include "ProjectToolsTypes.h"

UProjectToolsEditorSubsystem::UProjectToolsEditorSubsystem()
	: UEditorSubsystem()
{
	// SetupLightingContent
	static ConstructorHelpers::FClassFinder<AActor> SkySphereClassFinder(TEXT("/Engine/EngineSky/BP_Sky_Sphere"));
	if (SkySphereClassFinder.Succeeded())
	{
		LightingActors.Add(TSoftClassPtr<AActor>(SkySphereClassFinder.Class), TEXT("Sky Sphere"));
	}
	else
	{
		UE_LOG(LogProjectToolsTools, Error, TEXT("Can't find /Engine/EngineSky/BP_Sky_Sphere for SkySphere!"));
	}

	LightingActors.Add(ADirectionalLight::StaticClass(), TEXT("Directional Light"));
	LightingActors.Add(AExponentialHeightFog::StaticClass(), TEXT("Exponential Height Fog"));
	LightingActors.Add(APostProcessVolume::StaticClass(), TEXT("Post Process Volume"));
	LightingActors.Add(ASkyAtmosphere::StaticClass(), TEXT("Sky Atmosphere"));
	LightingActors.Add(ASkyLight::StaticClass(), TEXT("Sky Light"));

	// AutoSetupFolders
	AutoSetupFoldersMap.Add(TEXT("SM"), TEXT("Meshes"));
	AutoSetupFoldersMap.Add(TEXT("SK"), TEXT("Meshes"));

	// AutoSetupPack
	AutoSetupPackFolderName = TEXT("AA_Pack");
}

void UProjectToolsEditorSubsystem::SetupLightingContent()
{
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	if (!EditorActorSubsystem)
	{
		UE_LOG(LogProjectToolsTools, Error, TEXT("UEditorActorSubsystem is not initialized!"));
		return;
	}

	TArray<AActor*> AllLevelActors = EditorActorSubsystem->GetAllLevelActors();

	UKismetSystemLibrary::BeginTransaction(
		TEXT("SetupLightingContent"), FText::FromString(TEXT("Setup Lighting Content")), this);

	TArray<TSoftClassPtr<AActor>> LightingActorsClasses;
	LightingActors.GetKeys(LightingActorsClasses);

	// Destroy existing lighting actors
	for (AActor* LevelActor : AllLevelActors)
	{
		for (const TSoftClassPtr<AActor>& Class : LightingActorsClasses)
		{
			const UClass* ActorClass = Class.LoadSynchronous();
			if (!ActorClass)
			{
				continue;
			}

			if (LevelActor->GetClass()->IsChildOf(ActorClass))
			{
				UKismetSystemLibrary::CreateCopyForUndoBuffer(LevelActor);
				EditorActorSubsystem->DestroyActor(LevelActor);
			}
		}
	}

	// Spawn lighting actors
	for (const TSoftClassPtr<AActor>& Class : LightingActorsClasses)
	{
		UClass* ActorClass = Class.LoadSynchronous();
		if (!ActorClass)
		{
			continue;
		}

		AActor* SpawnedActor = EditorActorSubsystem->SpawnActorFromClass(ActorClass, FVector::ZeroVector);
		UKismetSystemLibrary::CreateCopyForUndoBuffer(SpawnedActor);

		FString* Label = LightingActors.Find(ActorClass);
		if (!Label)
		{
			*Label = FString(ActorClass->GetName());
		}

		SpawnedActor->SetActorLabel(*Label);
		SpawnedActor->SetFolderPath(FName("Lighting"));

		// Setup directional light
		if (ADirectionalLight* DirectionalLight = Cast<ADirectionalLight>(SpawnedActor))
		{
			DirectionalLight->SetActorRotation(FQuat(FRotator(-38.0f, -32.0f, 112.0f)), ETeleportType::None);
			DirectionalLight->SetMobility(EComponentMobility::Movable);
			DirectionalLight->GetComponent()->SetLightSourceAngle(0.7357f);
			DirectionalLight->GetComponent()->bUseTemperature = true;
			DirectionalLight->GetComponent()->Temperature = 6500.0f;
			DirectionalLight->GetComponent()->Intensity = 6.0f;
			DirectionalLight->GetComponent()->bEnableLightShaftOcclusion = true;
			DirectionalLight->GetComponent()->DistanceFieldShadowDistance = false;
			DirectionalLight->GetComponent()->bCastCloudShadows = true;
			DirectionalLight->GetComponent()->bCastShadowsOnAtmosphere = true;
			DirectionalLight->SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;;
		}

		// Setup exponential fog
		if (AExponentialHeightFog* ExponentialHeightFog = Cast<AExponentialHeightFog>(SpawnedActor))
		{
			ExponentialHeightFog->GetComponent()->FogDensity = 0.0436f;;
		}

		// Setup post process
		if (APostProcessVolume* PostProcessVolume = Cast<APostProcessVolume>(SpawnedActor))
		{
			PostProcessVolume->bEnabled = true;
			PostProcessVolume->bUnbound = true;
			PostProcessVolume->Settings.bOverride_AutoExposureMethod = true;
			PostProcessVolume->Settings.AutoExposureMethod = AEM_Manual;
			PostProcessVolume->Settings.bOverride_AutoExposureApplyPhysicalCameraExposure = true;
			PostProcessVolume->Settings.AutoExposureApplyPhysicalCameraExposure = false;
			PostProcessVolume->Settings.bOverride_LensFlareIntensity = true;
			PostProcessVolume->Settings.LensFlareIntensity = 0.0f;
			PostProcessVolume->Settings.bOverride_VignetteIntensity = true;
			PostProcessVolume->Settings.VignetteIntensity = 0.0f;
			PostProcessVolume->Settings.bOverride_BlueCorrection = true;
			PostProcessVolume->Settings.BlueCorrection = 0.0f;
			PostProcessVolume->Settings.bOverride_ExpandGamut = true;
			PostProcessVolume->Settings.ExpandGamut = 0.0f;
		}

		// Setup sky light
		if (ASkyLight* SkyLight = Cast<ASkyLight>(SpawnedActor))
		{
			SkyLight->GetLightComponent()->SetMobility(EComponentMobility::Movable);
			SkyLight->GetLightComponent()->bRealTimeCapture = true;
		}
	}

	UKismetSystemLibrary::EndTransaction();
}

void UProjectToolsEditorSubsystem::AutoSetupFolders()
{
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	if (!EditorActorSubsystem)
	{
		UE_LOG(LogProjectToolsTools, Error, TEXT("UEditorActorSubsystem is not initialized!"));
		return;
	}

	TArray<AActor*> AllLevelActors = EditorActorSubsystem->GetAllLevelActors();

	TArray<FString> LightingActorsLabels;
	LightingActors.GenerateValueArray(LightingActorsLabels);

	// Uses this arrays instead of direct TMap functions usage (for example AutoSetupFoldersMap.Contains()) because Epic's have bug with TMap initialization into editor (from settings) :(
	TArray<FString> AutoSetupFoldersMapKeys;
	TArray<FString> AutoSetupFoldersMapValues;
	AutoSetupFoldersMap.GenerateKeyArray(AutoSetupFoldersMapKeys);
	AutoSetupFoldersMap.GenerateValueArray(AutoSetupFoldersMapValues);

	for (AActor* LevelActor : AllLevelActors)
	{
		LevelActor->FixupActorFolder();

		const FString ActorLabel = LevelActor->GetActorLabel();

		// Skip lighting actor
		if (LightingActorsLabels.Contains(ActorLabel))
		{
			continue;
		}

		// Parse name to prefix and folders
		TArray<FString> Splits;
		ActorLabel.ParseIntoArray(Splits, TEXT("_"));

		if (Splits.Num() <= 1)
		{
			continue;
		}

		const int32 Index = AutoSetupFoldersMapKeys.Find(Splits[0]);
		if (Index == INDEX_NONE)
		{
			continue;
		}

		FString Path = AutoSetupFoldersMapValues[Index];

		// Check if suffix is index
		const int32 LastIndex = Splits.Last().IsNumeric() ? Splits.Num() - 2 : Splits.Num() - 1;

		for (int i = 1; i < LastIndex; i++)
		{
			Path = Path + TEXT("/") + Splits[i];
		}

		UKismetSystemLibrary::BeginTransaction(TEXT("AutoSetupFolders"), FText::FromString(TEXT("Auto Setup Folders")),
		                                       this);

		LevelActor->SetFolderPath(FName(Path));

		UKismetSystemLibrary::EndTransaction();
	}
}

void UProjectToolsEditorSubsystem::AutoSetupPack()
{
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	if (!EditorActorSubsystem)
	{
		UE_LOG(LogProjectToolsTools, Error, TEXT("UEditorActorSubsystem is not initialized!"));
		return;
	}

	TArray<AActor*> AllLevelActors = EditorActorSubsystem->GetAllLevelActors();

	TArray<FString> LightingActorsLabels;
	LightingActors.GenerateValueArray(LightingActorsLabels);

	// Uses this array instead of direct TMap functions usage (for example AutoSetupFoldersMap.Contains()) because Epic's have bug with TMap initialization into editor (from settings) :(
	TArray<FString> AutoSetupFoldersMapKeys;
	AutoSetupFoldersMap.GenerateKeyArray(AutoSetupFoldersMapKeys);

	for (AActor* LevelActor : AllLevelActors)
	{
		const FString ActorLabel = LevelActor->GetActorLabel();

		// Skip lighting actor
		if (LightingActorsLabels.Contains(ActorLabel))
		{
			continue;
		}

		// Parse name to prefix and folders
		TArray<FString> Splits;
		ActorLabel.ParseIntoArray(Splits, TEXT("_"));

		const int32 Index = AutoSetupFoldersMapKeys.Find(Splits[0]);
		if (Index != INDEX_NONE)
		{
			continue;
		}

		UKismetSystemLibrary::BeginTransaction(TEXT("AutoSetupPack"), FText::FromString(TEXT("Auto Setup Pack")), this);

		LevelActor->SetFolderPath(FName(*AutoSetupPackFolderName));

		UKismetSystemLibrary::EndTransaction();
	}
}

void UProjectToolsEditorSubsystem::SetupAffectDistanceFieldLighting()
{
	UEditorActorSubsystem* EditorActorSubsystem = GEditor->GetEditorSubsystem<UEditorActorSubsystem>();
	if (!EditorActorSubsystem)
	{
		UE_LOG(LogProjectToolsTools, Error, TEXT("UEditorActorSubsystem is not initialized!"));
		return;
	}

	TArray<AActor*> AllLevelActors = EditorActorSubsystem->GetAllLevelActors();

	UKismetSystemLibrary::BeginTransaction(
		TEXT("SetupAffectDistanceFieldLighting"), FText::FromString(TEXT("Setup Affect Distance Field Lighting")), this);

	TArray<AActor*> FoundMeshes;
	for (int y = 0; y < AllLevelActors.Num(); y++)
	{
		if (AllLevelActors[y]->IsA(AStaticMeshActor::StaticClass()))
		{
			FoundMeshes.AddUnique(AllLevelActors[y]);
			UKismetSystemLibrary::CreateCopyForUndoBuffer(AllLevelActors[y]);
		}
	}

	for (int i = 0; i < FoundMeshes.Num(); i++)
	{
		TArray<UStaticMeshComponent*> Components;
		FoundMeshes[i]->GetComponents<UStaticMeshComponent>(Components);
		
		for (int k = 0; k < Components.Num(); k++)
		{
			UStaticMeshComponent* StaticMeshComponent = Components[k];

			if (bIsAffected)
			{
				StaticMeshComponent->bAffectDistanceFieldLighting = false;
			}
			else
			{
				StaticMeshComponent->bAffectDistanceFieldLighting = true;
			}
		}
	}

	bIsAffected ? bIsAffected = false : bIsAffected = true;

	UE_LOG(LogTemp, Warning, TEXT("Static Mesh Actors number on the current level is %i"), FoundMeshes.Num());
	UE_LOG(LogTemp, Warning, TEXT("Affect Distance Field Lighting is set to: %s"), bIsAffected ? TEXT("true") : TEXT("false"));

	UKismetSystemLibrary::EndTransaction();
}
