using UnrealBuildTool;

public class UnrealPluginExampleEditorTarget : TargetRules {
	public UnrealPluginExampleEditorTarget(TargetInfo Target) : base(Target) {
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange(new string[] { "UnrealPluginExample" });
	}
}
