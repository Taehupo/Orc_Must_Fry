// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericTeamAgentInterface.h"
#include "OMFTypes.generated.h"

UENUM(BlueprintType)
enum EOMFWeapon
{
	Weapon_None		UMETA(DisplayName = "None"),

	Weapon_Fist		UMETA(DisplayName = "Fist"),

	Weapon_Sword	UMETA(DisplayName = "Sword"),

	Weapon_Crossbow	UMETA(DisplayName = "Crossbow"),

	Weapon_Shotgun	UMETA(DisplayName = "Shotgun"),

	Weapon_MAX		UMETA(Hidden),
};

UENUM(BlueprintType)
enum EOMFCharacterState
{
	BUILD_MODE		UMETA(DisplayName = "Build Mode"),
	FIGHT_MODE		UMETA(DisplayName = "Fight Mode"),
};

UENUM(BlueprintType)
enum EOMFTraps
{
	TRAP_NONE        UMETA(DisplayName = "None"),

	TRAP_ARROWWALL        UMETA(DisplayName = "Arrow Wall"),

	TRAP_BALLISTA    UMETA(DisplayName = "Ballista"),

	TRAP_BLADETORNADO    UMETA(DisplayName = "Blade Tornado"),
	TRAP_BLIZZARDTOWER   UMETA(DisplayName = "Blizzard Tower"),
	TRAP_FIRETOWER   UMETA(DisplayName = "Fire Tower"),
	TRAP_ICETOWER   UMETA(DisplayName = "IceT ower"),
	TRAP_TAR    UMETA(DisplayName = "Tar"),

	TRAP_BOMBER    UMETA(DisplayName = "Bomber"),
	TRAP_BOOMBARREL    UMETA(DisplayName = "Boom Barrel"),

	TRAP_SPIKE    UMETA(DisplayName = "Spike"),
	TRAP_SWINGMACE    UMETA(DisplayName = "Swing Mace"),

	TRAP_MAX        UMETA(Hidden),
};

UCLASS()
class UUtilitaries : public UObject
{
	GENERATED_BODY()

protected:
	static ETeamAttitude::Type OMFTeamAttitudeSolver(FGenericTeamId A, FGenericTeamId B);

public:
	static FGenericTeamId::FAttitudeSolverFunction* OMFAttitudeTeamSolver;
	
};


