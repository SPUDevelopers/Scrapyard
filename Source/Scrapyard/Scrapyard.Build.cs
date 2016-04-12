// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Scrapyard : ModuleRules
{
	public Scrapyard(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "OnlineSubsystem", "OnlineSubsystemUtils", "UMG" });

        DynamicallyLoadedModuleNames.Add("OnlineSubsystemNull");
	}
}
