// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFBallista.h"
#include "OMFBomber.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFBomber : public AOMFShootingTrap
{
	GENERATED_BODY()

	
	//Methods
public:

	virtual void SetupProjectile(class AOMFProjectile* CurrentProjectile, FTransform _WorldTransform);
	
};
