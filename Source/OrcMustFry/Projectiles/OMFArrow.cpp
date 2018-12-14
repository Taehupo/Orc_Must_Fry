// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFArrow.h"

#include "OMFProjectileComponent.h"

bool AOMFArrow::IsValidActorForCollision(AActor* _OtherActor)
{
	if (Super::IsValidActorForCollision(_OtherActor))
	{
		TargetAttach = _OtherActor;
		return true;
	}

	return false;
}

void AOMFArrow::OnLifeEnded()
{
	Super::OnLifeEnded();

	if (nullptr != TargetAttach)
		AttachToActor(TargetAttach, FAttachmentTransformRules::KeepWorldTransform);
}