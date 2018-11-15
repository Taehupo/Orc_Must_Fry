// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFWeaponMelee.h"

#include "Components/StaticMeshComponent.h"

void AOMFWeaponMelee::BeginPlay()
{
	Super::BeginPlay();
}

//Defines default behavior for all melee weapons
void AOMFWeaponMelee::Attack()
{
	Super::Attack();

	if (nullptr != MeshComponent)
	{
		//if you overlap actor, you "save" them in the array, then destroy them
		TArray<AActor*> CollisionedActors;
		MeshComponent->GetOverlappingActors(CollisionedActors);

		//This is a foreach (This automatically iterates on a container without overflowing,
		//you store the object on the variable you declare at first, the thing behind the : is the container you go through)
		for (auto Actor : CollisionedActors)
		{
			Actor->Destroy();
		}

	}
}