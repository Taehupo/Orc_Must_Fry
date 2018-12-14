// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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