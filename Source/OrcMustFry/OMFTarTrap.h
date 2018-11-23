// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTrap.h"
#include "OMFTarTrap.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFTarTrap : public AOMFTrap
{
	GENERATED_BODY()
	
public:
	virtual void OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnValidEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
