// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBullet.h"

AOMFBullet::AOMFBullet()
{
	//Super::AOMFProjectile();
}

void AOMFBullet::BeginPlay()
{
	Super::BeginPlay();
}

void AOMFBullet::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

void AOMFBullet::InitProjectile(FVector Location, FVector ForwardWeapon)
{
	Super::InitProjectile(Location, ForwardWeapon);
}

void AOMFBullet::OnValidHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//Bullet Specific Behavior
}