// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBoomBarrel.h"

#include "OMFProjectile.h"
#include "OMFCharacter.h"

#include "Components/StaticMeshComponent.h"

// Called when the game starts or when spawned
void AOMFBoomBarrel::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != MeshComponent)
	{
		MeshComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &AOMFBoomBarrel::OnMeshBeginOverlap);
	}
}

void AOMFBoomBarrel::OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AOMFProjectile* OtherChar = Cast<AOMFProjectile>(OtherActor);

	if (nullptr != OtherChar && GetLifeSpan() == 0.f && UUtilitaries::OMFAttitudeTeamSolver(OMFTeamId, OtherChar->GetGenericTeamId()) == ETeamAttitude::Hostile)
	{
		Attack();
		SetLifeSpan(3.f);
	}
}
