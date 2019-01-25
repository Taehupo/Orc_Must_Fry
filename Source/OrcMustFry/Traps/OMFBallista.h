// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFShootingTrap.h"
#include "OMFBallista.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFBallista : public AOMFShootingTrap
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

		//Methods
public:
	virtual void SetupProjectile(class AOMFProjectile* CurrentProjectile, FTransform _WorldTransform);
	
	//virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	//virtual void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Attributes
protected:
	//class AOMFCharacter* Target;
};
