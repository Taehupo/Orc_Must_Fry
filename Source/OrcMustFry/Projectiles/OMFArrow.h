// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFNormalProjectile.h"
#include "OMFArrow.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFArrow : public AOMFNormalProjectile
{
	GENERATED_BODY()

		//Methods
public:
	virtual bool IsValidActorForCollision(AActor* _OtherActor);

	virtual void OnLifeEnded();

	//Attributes
protected:

	class AActor* TargetAttach;

};
