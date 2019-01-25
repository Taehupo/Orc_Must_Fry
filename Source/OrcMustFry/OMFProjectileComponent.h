// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "OMFProjectileComponent.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API UOMFProjectileComponent : public UProjectileMovementComponent
{
	GENERATED_BODY()
	
public:
	/** Allow the projectile to track towards its homing target. */
	virtual FVector ComputeVelocity(FVector InitialVelocity, float DeltaTime) const override;
	
	//Attributes
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Homing)
	bool bForceHoming;

};
