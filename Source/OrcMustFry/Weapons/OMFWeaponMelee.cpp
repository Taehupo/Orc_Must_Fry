// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFWeaponMelee.h"

#include "Components/StaticMeshComponent.h"
#include "ActorSequenceComponent.h"

#include "OMFCharacter.h"
#include "OMFProjectile.h"

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
			if (IsValidActorForCollision(Actor))
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("MeleeWeapon : %s hit : %s"), *GetNameSafe(this), *GetNameSafe(Actor)));
			}
		}
	}
}

bool AOMFWeaponMelee::IsValidActorForCollision(AActor* _OtherActor)
{
	/*if (nullptr != _OtherActor && !_OtherActor->IsA<AOMFProjectile>() && !_OtherActor->IsA<AOMFTrap>() && !_OtherActor->IsA<AOMFWeapon>())
		return true;*/

	if (nullptr == _OtherActor || _OtherActor->IsA<AOMFProjectile>() || _OtherActor->IsA<AOMFWeapon>() || GetTeamAttitudeTowards(*_OtherActor) == ETeamAttitude::Friendly)
		return false;

	return true;
}