// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFShotgun.h"

#include "OMFProjectile.h"
#include "OMFBullet.h"

#include "Components/StaticMeshComponent.h"

void AOMFShotgun::Attack()
{
	Super::Attack();

	//Instantiate projectiles with directions directly in sockets
	if (nullptr != GetWorld())
	{
		AOMFBullet* CurrentProjectile = nullptr;

		CurrentProjectile = GetWorld()->SpawnActor<AOMFBullet>(ProjectileClass);

		if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->MeshComponent)
		{
			CurrentProjectile->InitProjectile(MeshComponent->GetSocketLocation(TEXT("ProjectileSocket1")), MeshComponent->GetSocketRotation(TEXT("ProjectileSocket1")).Vector());
		}

		CurrentProjectile = GetWorld()->SpawnActor<AOMFBullet>(ProjectileClass);

		if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->MeshComponent)
		{
			CurrentProjectile->InitProjectile(MeshComponent->GetSocketLocation(TEXT("ProjectileSocket2")), MeshComponent->GetSocketRotation(TEXT("ProjectileSocket2")).Vector());
		}
	}
}

