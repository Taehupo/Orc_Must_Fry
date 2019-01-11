// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFShootingTrap.h"

#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

#include "Projectiles/OMFProjectile.h"

AOMFShootingTrap::AOMFShootingTrap()
{
	StartingProjectilePointTag = "ProjSocket";

	NbProjectiles = 1;
}

// Called when the game starts or when spawned
void AOMFShootingTrap::BeginPlay()
{
	Super::BeginPlay();

	if (StartingProjectilesPoints.Num() == 0)
	{
		//Get all sceneComponents with the tag StartingProjectilePointTag to get all relative spawning points from the actor

		TArray<UActorComponent*> AllSceneComps = GetComponentsByClass(USceneComponent::StaticClass());

		for (auto ActorComp : AllSceneComps)
		{
			USceneComponent* SceneComp = Cast<USceneComponent>(ActorComp);

			if (nullptr != SceneComp && SceneComp->ComponentHasTag(StartingProjectilePointTag))
			{
				StartingProjectilesPoints.Add(SceneComp->GetRelativeTransform());
			}
		}

		//Get all sockets with the tag for the proj

		TArray<UActorComponent*> AllMeshComps = GetComponentsByClass(UStaticMeshComponent::StaticClass());

		for (auto ActorComp : AllMeshComps)
		{
			USceneComponent* MeshComp = Cast<USceneComponent>(ActorComp);

			if (nullptr != MeshComp)
			{
				TArray<FName> AllSockets = MeshComp->GetAllSocketNames();

				for (auto Socket : AllSockets)
				{
					if (Socket.ToString().Contains(StartingProjectilePointTag.ToString()))
					{
						StartingProjectilesPoints.Add(MeshComp->GetSocketTransform(Socket, ERelativeTransformSpace::RTS_Actor));
					}
				}
			}
		}
	}
}

void AOMFShootingTrap::Attack()
{	
	CurrentIndexTarget = 0;

	for (auto ProjPoint : StartingProjectilesPoints)
	{
		if (nullptr != GetWorld() && CurrentIndexTarget < NbProjectiles)
		{
			AOMFProjectile* CurrentProjectile = nullptr;

			ProjPoint = ProjPoint * GetActorTransform();

			ProjPoint.SetScale3D(FVector::OneVector);

			CurrentProjectile = GetWorld()->SpawnActor<AOMFProjectile>(ProjectileClass, ProjPoint);

			SetupProjectile(CurrentProjectile, ProjPoint);

			CurrentIndexTarget++;
		}
	}

}

void AOMFShootingTrap::SetupProjectile(class AOMFProjectile* CurrentProjectile, FTransform _WorldTransform)
{
	if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->MeshComponent)
	{
		CurrentProjectile->InitProjectile(_WorldTransform.GetLocation(), _WorldTransform.GetRotation().Vector(), GetGenericTeamId());
	}
}