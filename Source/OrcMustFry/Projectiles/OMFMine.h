// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFAOEProjectile.h"
#include "OMFMine.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFMine : public AOMFAOEProjectile
{
	GENERATED_BODY()
	
	
	//Methods
public:
	virtual void OnProjectileHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
};
