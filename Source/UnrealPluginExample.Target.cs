using UnrealBuildTool;

public class UnrealPluginExampleTarget : TargetRules {
	public UnrealPluginExampleTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange(new string[] { "UnrealPluginExample" });
	}
}
