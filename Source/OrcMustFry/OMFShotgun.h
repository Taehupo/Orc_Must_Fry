// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFWeaponRanged.h"
#include "OMFShotgun.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFShotgun : public AOMFWeaponRanged
{
	GENERATED_BODY()
	
	
	//Methods
public:
	virtual void Attack();
	
};
