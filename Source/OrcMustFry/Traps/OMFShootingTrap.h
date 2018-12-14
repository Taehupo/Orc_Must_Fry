// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTriggerTrap.h"
#include "OMFShootingTrap.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFShootingTrap : public AOMFTriggerTrap
{
	GENERATED_BODY()
	
public:
	AOMFShootingTrap();

	// Called when the game starts or when spawned
	virtual void BeginPlay();

	//Methods
public:

	virtual void Attack();

	virtual void SetupProjectile(class AOMFProjectile* CurrentProjectile, FTransform _WorldTransform);

	//Attributes
protected:

	UPROPERTY(EditAnywhere, Category = OMFShootingTrap)
	TSubclassOf<class AOMFProjectile> ProjectileClass;

	TArray<FTransform> StartingProjectilesPoints;

	UPROPERTY(EditAnywhere, Category = OMFShootingTrap)
	FName StartingProjectilePointTag;

	UPROPERTY(EditAnywhere, Category = OMFShootingTrap)
	int32 NbProjectiles;

	int32 CurrentIndexTarget;
	
};
