// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFWeapon.h"
#include "OMFWeaponMelee.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFWeaponMelee : public AOMFWeapon
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay();

	//Methods
public:

	virtual void Attack();

	//Attributes
protected:

};
