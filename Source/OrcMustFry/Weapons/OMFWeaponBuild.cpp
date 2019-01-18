// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFWeaponBuild.h"
#include "OMFCharacter.h"
#include "Engine/World.h"
#include "Engine.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

AOMFWeaponBuild::AOMFWeaponBuild()
{
	PrimaryActorTick.bCanEverTick = true;

	trapIndex = 0;
}

void AOMFWeaponBuild::BeginPlay()
{
	Super::BeginPlay();

	currentTrap = GetWorld()->SpawnActor<AOMFTrap>(trapClasses[trapIndex]);
	currentTrap->MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AOMFWeaponBuild::Attack()
{
	SpawnTrap();
}

void AOMFWeaponBuild::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FCollisionQueryParams Params;

	if (nullptr != OwnerCharacter)
	{
		TArray<FHitResult> hitResult;
		FVector raycastStart = OwnerCharacter->GetActorLocation();
		FVector raycastEnd = raycastStart + (OwnerCharacter->GetControlRotation().Vector() * 1000.0f);

		bool validHitResult = false;

		GetWorld()->LineTraceMultiByChannel(hitResult, raycastStart, raycastEnd, ECollisionChannel::ECC_Visibility, Params);

		DrawDebugLine(GetWorld(), raycastStart, raycastEnd, FColor::Red);

		for (FHitResult hit : hitResult)
		{
			if (hit.bBlockingHit && nullptr != hit.GetActor() && hit.GetActor()->ActorHasTag("groundTrap"))
			{
				FVector pos = hit.ImpactPoint;
				pos.Z = OwnerCharacter->GetActorLocation().Z;
				pos.Y = (int32)(pos.Y / currentTrap->trapSize) * currentTrap->trapSize;
				pos.X = (int32)(pos.X / currentTrap->trapSize) * currentTrap->trapSize;
				currentTrap->SetActorLocation(pos);
				currentTrap->OMFTeamId = OwnerCharacter->GetGenericTeamId();
			}
		}
	}
}

AOMFTrap * AOMFWeaponBuild::SpawnTrap()
{
	FCollisionQueryParams Params;
	AOMFTrap* newTrap = nullptr;
	if (nullptr != OwnerCharacter)
	{
		TArray<FHitResult> hitResult;
		FVector raycastStart = OwnerCharacter->GetActorLocation();
		FVector raycastEnd = raycastStart + (OwnerCharacter->GetControlRotation().Vector() * 1000.0f);

		bool validHitResult = false;

		GetWorld()->LineTraceMultiByChannel(hitResult, raycastStart, raycastEnd, ECollisionChannel::ECC_Visibility, Params);

		DrawDebugLine(GetWorld(), raycastStart, raycastEnd, FColor::Red);

		for (FHitResult hit : hitResult)
		{
			if (hit.bBlockingHit && nullptr != hit.GetActor() && hit.GetActor()->ActorHasTag("groundTrap"))
			{
				FVector pos = hit.ImpactPoint;
				pos.Z = OwnerCharacter->GetActorLocation().Z;
				pos.Y = (int32)(pos.Y / currentTrap->trapSize) * currentTrap->trapSize;
				pos.X = (int32)(pos.X / currentTrap->trapSize) * currentTrap->trapSize;
				newTrap = GetWorld()->SpawnActor<AOMFTrap>(trapClasses[trapIndex]);
				newTrap->SetActorLocation(pos);
				newTrap->OMFTeamId = OwnerCharacter->GetGenericTeamId();
			}
		}
	}

	return newTrap;
}