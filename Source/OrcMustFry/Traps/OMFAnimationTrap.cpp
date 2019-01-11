// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFAnimationTrap.h"

#include "Components/StaticMeshComponent.h"

#include "OMFCharacter.h"

AOMFAnimationTrap::AOMFAnimationTrap()
{
	MeshAnimated = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshAnimated"));

	if (nullptr != SceneComponent && nullptr != MeshAnimated)
	{
		MeshAnimated->SetupAttachment(SceneComponent);
	}

}

void AOMFAnimationTrap::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	/*if (nullptr != MeshComponent && nullptr != MeshAnimated)
	{
		MeshAnimated->AttachToComponent(MeshComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepWorld, false));
	}*/
}

void AOMFAnimationTrap::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != MeshAnimated)
	{
		MeshAnimated->OnComponentBeginOverlap.AddUniqueDynamic(this, &AOMFAnimationTrap::OnMeshBeginOverlap);
	}
}

void AOMFAnimationTrap::OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AOMFCharacter* OtherChar = Cast<AOMFCharacter>(OtherActor);

	if (nullptr != OtherChar && OMFTeamAttitudeSolver(GetGenericTeamId(), OtherChar->GetGenericTeamId()) == ETeamAttitude::Hostile)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Actor : %s Hit"), *GetNameSafe(this)));
	}
}