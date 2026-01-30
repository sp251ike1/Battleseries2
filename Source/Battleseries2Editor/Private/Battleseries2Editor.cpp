#include "Battleseries2Editor.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"

#define LOCTEXT_NAMESPACE "FBattleseries2EditorModule"

void FBattleseries2EditorModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("Editor module successfully loaded."));

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	IAssetTools& assetToolsModule = IAssetTools::Get();

	EAssetTypeCategories::Type assetType = assetToolsModule.RegisterAdvancedAssetCategory
	(
		//internal name
		FName(TEXT("MSV")),
		//THE VISIBLE NAME
		//Multi-Seat Vehicles = what will show up in the content browser's right click menu
		LOCTEXT("CustomAssetCategory", "BattleseriesVehicles")
	);
}

void FBattleseries2EditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FBattleseries2EditorModule, Battleseries2Editor)