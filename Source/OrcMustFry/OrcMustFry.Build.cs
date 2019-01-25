// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OrcMustFry : ModuleRules
{
	public OrcMustFry(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "MovieScene", "ActorSequence", "GameplayTasks" });

        PublicIncludePaths.AddRange(new string[] { "OrcMustFry/Traps", "OrcMustFry/Weapons", "OrcMustFry/Projectiles", "OrcMustFry/Controllers", "OrcMustFry/Pawns" });

    }
}
