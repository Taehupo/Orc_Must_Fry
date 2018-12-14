// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFProjectileComponent.h"


/** Allow the projectile to track towards its homing target. */
FVector UOMFProjectileComponent::ComputeVelocity(FVector ComputeVelocity, float DeltaTime) const
{
	if (!bForceHoming)
		return Super::ComputeVelocity(ComputeVelocity, DeltaTime);
	
	FVector Direction = (HomingTargetComponent->GetComponentLocation() - UpdatedComponent->GetComponentLocation()).GetSafeNormal();
	
	Direction = Direction * ComputeVelocity.Size() + (Direction * HomingAccelerationMagnitude * DeltaTime);
 
	return Direction;
}

