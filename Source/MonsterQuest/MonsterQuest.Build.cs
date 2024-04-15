// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MonsterQuest : ModuleRules
{
	public MonsterQuest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.Add(ModuleDirectory);

		PublicDependencyModuleNames.AddRange(new string[] { "UMG", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
