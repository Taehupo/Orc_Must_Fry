// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTriggerTrap.h"
#include "OMFPermanentTrap.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFPermanentTrap : public AOMFTriggerTrap
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AOMFPermanentTrap();
	
	virtual void FinishAttack();
	
	//Methods
public:

	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	virtual void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
