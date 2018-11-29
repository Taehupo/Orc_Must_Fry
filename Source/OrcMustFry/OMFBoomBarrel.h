// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTrap.h"
#include "OMFBoomBarrel.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFBoomBarrel : public AOMFTrap
{
	GENERATED_BODY()

	//Methods
public:
	virtual void OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
