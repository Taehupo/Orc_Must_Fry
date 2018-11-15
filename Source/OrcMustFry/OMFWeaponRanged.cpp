// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFWeaponRanged.h"

#include "OMFProjectile.h"
#include "Engine/World.h"

#include "Components/StaticMeshComponent.h"

// Called when the game starts or when spawned
void AOMFWeaponRanged::BeginPlay()
{
	Super::BeginPlay();

	//Set collision preset to not collide with anything
	if (nullptr != MeshComponent)
		MeshComponent->SetCollisionProfileName(TEXT("NoCollision"));

}

void AOMFWeaponRanged::Attack()
{
	Super::Attack();
	if (nullptr != GetWorld())
	{
		//Instantiate projectile
		AOMFProjectile* CurrentProjectile = nullptr;

		CurrentProjectile = GetWorld()->SpawnActor<AOMFProjectile>(ProjectileClass);

		if (nullptr != CurrentProjectile && nullptr != MeshComponent)
		{
			//Spawn projectile from socket, and roation is actor forward
			CurrentProjectile->InitProjectile(MeshComponent->GetSocketLocation(TEXT("ProjectileSocket")),GetActorForwardVector());
		}
	}
}