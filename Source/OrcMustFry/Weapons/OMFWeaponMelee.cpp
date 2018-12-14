// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFWeaponMelee.h"

#include "Components/StaticMeshComponent.h"

#include "ActorSequenceComponent.h"

AOMFWeaponMelee::AOMFWeaponMelee()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//AttackAnimation = CreateDefaultSubobject<UActorSequenceComponent>(TEXT("SequenceComponent"));
}

void AOMFWeaponMelee::BeginPlay()
{
	Super::BeginPlay();
}

void AOMFWeaponMelee::Attack()
{
	Super::Attack();

	if (nullptr != MeshComponent)
	{
		TArray<AActor*> CollisionedActors;
		MeshComponent->GetOverlappingActors(CollisionedActors);

		for (auto Actor : CollisionedActors)
		{
			Actor->Destroy();
		}

	}
}