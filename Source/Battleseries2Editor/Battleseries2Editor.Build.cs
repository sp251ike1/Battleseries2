using UnrealBuildTool;

public class Battleseries2Editor : ModuleRules
{
    public Battleseries2Editor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "UnrealEd",           // Required for UFactory and other editor classes
            "AssetTools",         // If you're registering asset types
            "EditorStyle",
            "Slate",
            "SlateCore",
            "Battleseries2"
        });
    }
}
