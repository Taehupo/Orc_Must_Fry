// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFWeaponControlledProj.h"

#include "OMFMamouchka.h"
#include "OMFMamouchkaPawn.h"
#include "OMFCharacter.h"

#include "GameFramework/Controller.h"

#include "Components/StaticMeshComponent.h"

void AOMFWeaponControlledProj::Attack()
{
	if (nullptr != ControlledProjectile)
		return;

	TArray<AOMFProjectile*> ProjSpawned = SpawnProjectile();

	if (ProjSpawned.Num() > 0)
		ControlledProjectile = Cast<AOMFMamouchka>(ProjSpawned[0]);
	else
		return;

	if (nullptr != OwnerCharacter && nullptr != ControlledProjectile && nullptr != ControlledProjectile->CurrentMamouchkaPawn)
	{
		AController* Controller = OwnerCharacter->GetController();
		if (nullptr != Controller)
		{
			Controller->Possess(ControlledProjectile->CurrentMamouchkaPawn);
			CurrentController = Controller;

			ControlledProjectile->EndLifeDel.BindDynamic(this, &AOMFWeaponControlledProj::ProjectileEnded);
		}
	}
}

void AOMFWeaponControlledProj::ProjectileEnded()
{
	if (nullptr != CurrentController )
	{
		CurrentController->Possess(OwnerCharacter);
		ControlledProjectile = nullptr;
	}
}