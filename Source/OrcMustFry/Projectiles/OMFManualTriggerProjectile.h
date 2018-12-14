// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/OMFWeaponRanged.h"
#include "OMFManualTriggerProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFManualTriggerProjectile : public AOMFWeaponRanged
{
	GENERATED_BODY()
	
	
	//Methods
public:
	virtual void Attack();
	virtual void AttackBis();
	
	//Attributes
protected:

	TArray<class AOMFProjectile*> ProjectileList;

	UPROPERTY(EditAnywhere, Category = ManualTrigger)
	int32 NbMaxProjectile;
};
