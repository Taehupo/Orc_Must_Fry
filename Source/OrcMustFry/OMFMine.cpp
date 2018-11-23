// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFMine.h"
#include "Components/InputComponent.h"
#include "OrcMustFryCharacter.h"
#include "Public/EngineUtils.h"

AOMFMine::AOMFMine()
{

}

void AOMFMine::BeginPlay()
{
	Super::BeginPlay();
	
	for (TActorIterator<AOrcMustFryCharacter> Actoritr(GetWorld()); Actoritr; ++Actoritr)
	{
		playerOwner = *Actoritr;
	}

	playerOwner->AddMine(this);
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
	FRotator rotation = Hit.Normal.ToOrientationRotator();
	SetActorRotation(rotation);
}

void AOMFMine::Explode()
{
	UE_LOG(LogTemp, Log, TEXT("I HAZ BOOM MANUEL !"));
	Destroy();
}