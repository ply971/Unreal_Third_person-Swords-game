// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class A1U : ModuleRules
{
	public A1U(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
