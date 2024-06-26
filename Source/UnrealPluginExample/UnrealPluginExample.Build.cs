using System.IO;
using UnrealBuildTool;

public class UnrealPluginExample : ModuleRules {
	public UnrealPluginExample(ReadOnlyTargetRules Target) : base(Target) {
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "..", "ThirdParty", "LiveAwareLabs", "recorder-unreal-plugin.lib"));
		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "..", "ThirdParty", "LiveAwareLabs"));

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
