// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFGrenade.h"

AOMFGrenade::AOMFGrenade()
{
	projectileComponent->bShouldBounce = true;
	projectileComponent->Bounciness = 0.3f;
}

void AOMFGrenade::BeginPlay()
{
	Super::BeginPlay();
}

void AOMFGrenade::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void AOMFGrenade::InitProjectile(FVector Location, FVector ForwardWeapon)
{
	Super::InitProjectile(Location, ForwardWeapon);
}

void AOMFGrenade::OnValidHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Log, TEXT("I GRENADE, HAZ HIT SOMETING !"));
}
