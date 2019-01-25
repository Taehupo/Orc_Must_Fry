// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFNormalProjectile.h"
#include "OMFBullet.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFBullet : public AOMFNormalProjectile
{
	GENERATED_BODY()

	//Methods
public:

	virtual void OnLifeEnded();

};
