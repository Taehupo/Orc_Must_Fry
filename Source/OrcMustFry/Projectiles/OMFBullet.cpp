// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBullet.h"

void AOMFBullet::OnLifeEnded()
{
	Super::OnLifeEnded();
	SetActorHiddenInGame(true);
}