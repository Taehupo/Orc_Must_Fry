// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTriggerTrap.h"
#include "OMFSpikeTrap.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFSpikeTrap : public AOMFTriggerTrap
{
	GENERATED_BODY()

	//Methods
public:

	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
};
