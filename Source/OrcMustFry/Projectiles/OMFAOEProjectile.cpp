// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFAOEProjectile.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AOMFAOEProjectile::AOMFAOEProjectile() : Super()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	AOETrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

	if (nullptr != AOETrigger && nullptr != MeshComponent)
		AOETrigger->SetupAttachment(MeshComponent);

}
