// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFWeapon.h"
#include "OMFWeaponRanged.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFWeaponRanged : public AOMFWeapon
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay();

	
	//Methods
public:

	virtual void Attack();

	//Attributes
protected:

	//Projectile that you need to spawn
	UPROPERTY(EditAnywhere, Category = OMFAttack)
	TSubclassOf<class AOMFProjectile> ProjectileClass;
};
