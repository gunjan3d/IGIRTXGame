// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class IGIRTX : ModuleRules
{
	public IGIRTX(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput","GameplayTasks", "UMG" });
	}
}
