// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Temporal_Invasion : ModuleRules
{
	public Temporal_Invasion(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG"});
	}
}
