// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFAOEProjectile.h"
#include "OMFGrenade.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFGrenade : public AOMFAOEProjectile
{
	GENERATED_BODY()
	
	
public:
	virtual void OnProjectileHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
};
