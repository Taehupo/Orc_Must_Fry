// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFTrap.h"

#include "Components/StaticMeshComponent.h"

AOMFTrap::AOMFTrap()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = SceneComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	if (nullptr != SceneComponent && nullptr != MeshComponent)
	{
		MeshComponent->SetupAttachment(SceneComponent);
	}

	trapSize = 50.0f;
}

bool AOMFTrap::CanAttack()
{
	return true;
}
