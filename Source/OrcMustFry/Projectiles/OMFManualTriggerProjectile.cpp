// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFManualTriggerProjectile.h"

#include "OMFProjectile.h"

void AOMFManualTriggerProjectile::Attack()
{
	if (ProjectileList.Num() < NbMaxProjectile)
	{
		TArray<AOMFProjectile*> CurrentProjectile = SpawnProjectile();

		for(auto Proj : CurrentProjectile)
		{
			ProjectileList.Add(Proj);
		}
	}
}

void AOMFManualTriggerProjectile::AttackBis()
{
	for (auto Proj : ProjectileList)
	{
		Proj->OnLifeEnded();
	}

	ProjectileList.Empty();
}