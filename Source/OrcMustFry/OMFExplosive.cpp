// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFExplosive.h"

AOMFExplosive::AOMFExplosive()
{

}

void AOMFExplosive::BeginPlay()
{
	Super::BeginPlay();
}

void AOMFExplosive::EndPlay(const EEndPlayReason::Type EndPlayReason)
{

}

void AOMFExplosive::Tick(float deltaTime)
{

}

void AOMFExplosive::InitProjectile(FVector Location, FVector ForwardWeapon)
{
	Super::InitProjectile(Location, ForwardWeapon);
}

void AOMFExplosive::OnValidHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Explode();
}

void AOMFExplosive::Explode()
{
	UE_LOG(LogTemp, Log, TEXT("I HAZ BOOM BOOM !"));
	Destroy();
}