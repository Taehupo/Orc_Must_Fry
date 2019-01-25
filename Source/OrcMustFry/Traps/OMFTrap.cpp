// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFTrap.h"

#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "PhysicsEngine/BodySetup.h"

AOMFTrap::AOMFTrap()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	RootComponent = SceneComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	BuildTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BuildTrigger"));

	if (nullptr != SceneComponent && nullptr != MeshComponent && nullptr != BuildTrigger)
	{
		MeshComponent->SetupAttachment(SceneComponent);
	}

	bIsActive = true;
}

void AOMFTrap::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != SceneComponent && nullptr != BuildTrigger)
	{
		BuildTrigger->AttachToComponent(SceneComponent,FAttachmentTransformRules(EAttachmentRule::KeepRelative,
			EAttachmentRule::KeepWorld,EAttachmentRule::KeepRelative,false));
	}
}


bool AOMFTrap::CanAttack()
{
	return true && bIsActive;
}

void AOMFTrap::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	if (OMFTeamID != NewTeamID)
	{
		OMFTeamID = NewTeamID;
	}
}

int32 AOMFTrap::GetTrapSize()
{
	return BuildTrigger->GetScaledBoxExtent().X;
}

void AOMFTrap::ChangeBuildState(bool _CanBuild)
{
	
}