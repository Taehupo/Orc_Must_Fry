// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Traps/OMFTriggerTrap.h"
#include "OMFTypes.h"
#include "OMFBoomBarrel.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFBoomBarrel : public AOMFTriggerTrap
{
	GENERATED_BODY()
	
public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//Methods
public:

	UFUNCTION()
	virtual void OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
};
