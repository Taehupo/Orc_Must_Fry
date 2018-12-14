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

	virtual TArray<class AOMFProjectile*> SpawnProjectile();

	//Attributes
protected:

	UPROPERTY(EditAnywhere, Category = OMFAttack)
	TSubclassOf<class AOMFProjectile> ProjectileClass;

	TArray<FTransform> StartingProjectilesPoints;

	UPROPERTY(EditAnywhere, Category = OMFShootingTrap)
		FName StartingProjectilePointTag;

	UPROPERTY(EditAnywhere, Category = OMFShootingTrap)
		int32 NbProjectiles;
};
