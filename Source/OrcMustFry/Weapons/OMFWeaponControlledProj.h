// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFWeaponRanged.h"
#include "OMFWeaponControlledProj.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFWeaponControlledProj : public AOMFWeaponRanged
{
	GENERATED_BODY()
	
	//Methods
public:
	virtual void Attack();

	UFUNCTION()
	void ProjectileEnded();

	//Attributes
public:

	class AOMFMamouchka* ControlledProjectile;
	
	class AController* CurrentController;
};
