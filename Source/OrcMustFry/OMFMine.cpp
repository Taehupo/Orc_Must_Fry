// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFMine.h"

AOMFMine::AOMFMine()
{

}

void AOMFMine::BeginPlay()
{
	Super::BeginPlay();
}

void AOMFMine::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

}

void AOMFMine::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void AOMFMine::InitProjectile(FVector Location, FVector ForwardWeapon)
{
	Super::InitProjectile(Location, ForwardWeapon);
}

void AOMFMine::OnValidHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}