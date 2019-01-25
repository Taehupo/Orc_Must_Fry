// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBomber.h"

#include "OMFProjectile.h"
#include "OMFCharacter.h"

void AOMFBomber::SetupProjectile(class AOMFProjectile* CurrentProjectile, FTransform _WorldTransform)
{
	//Super::SetupProjectile(CurrentProjectile, _WorldTransform);

	if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->ProjectileComponent && OverlappedActors.Num() > CurrentIndexTarget && nullptr != OverlappedActors[CurrentIndexTarget])
	{
		FVector DirectionToTarget = OverlappedActors[CurrentIndexTarget]->GetActorLocation() - _WorldTransform.GetLocation();
		DirectionToTarget.Normalize();
		CurrentProjectile->ProjectileComponent->Velocity = DirectionToTarget * CurrentProjectile->ProjectileComponent->InitialSpeed;
	}
}
