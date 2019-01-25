// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFWeaponRanged.h"

#include "OMFProjectile.h"

#include "Components/StaticMeshComponent.h"

// Called when the game starts or when spawned
void AOMFWeaponRanged::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != MeshComponent)
		MeshComponent->SetCollisionProfileName(TEXT("NoCollision"));

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

void AOMFWeaponRanged::Attack()
{
	Super::Attack();
	SpawnProjectile();
}

TArray<class AOMFProjectile*> AOMFWeaponRanged::SpawnProjectile()
{
	TArray<class AOMFProjectile*> AllProj;
	int IndexProj = 0;
	for (auto ProjPoint : StartingProjectilesPoints)
	{
		if (nullptr != GetWorld() && IndexProj < NbProjectiles)
		{
			AOMFProjectile* CurrentProjectile = nullptr;

			ProjPoint = ProjPoint * GetActorTransform();

			ProjPoint.SetScale3D(FVector::OneVector);

			CurrentProjectile = GetWorld()->SpawnActorDeferred<AOMFProjectile>(ProjectileClass, ProjPoint);

			CurrentProjectile->InitProjectile(ProjPoint.GetLocation(), ProjPoint.GetRotation().Vector(), GetGenericTeamId());

			if (nullptr != CurrentProjectile)
				CurrentProjectile->FinishSpawning(ProjPoint);

			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Projectile spawned : %s "), *GetNameSafe(CurrentProjectile)));

			AllProj.Add(CurrentProjectile);
		}
		IndexProj++;
	}

	return AllProj;
}