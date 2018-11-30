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
	
	//Find player inside level to register to your player
	for (TActorIterator<AOrcMustFryCharacter> Actoritr(GetWorld()); Actoritr; ++Actoritr)
	{
		playerOwner = *Actoritr;
	}

	playerOwner->AddMine(this);
}

void AOMFMine::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//Is there for endLife events, or just some stuff. Like spawning a VFX or something.
}

//Because this needs to be done :V You can add some behaviors here
void AOMFMine::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
}

//Not really needed. But if you want to add behavior it'll be here.
void AOMFMine::InitProjectile(FVector Location, FVector ForwardWeapon)
{
	Super::InitProjectile(Location, ForwardWeapon);
}

//Try to rotate the mine the good way :V TRY
void AOMFMine::OnValidHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	FRotator rotation = Hit.Normal.ToOrientationRotator();
	SetActorRotation(rotation);
}

//Called by the player when hitting the explode key. NOT TO BE CALLED BY ANYTHING ELSE.
void AOMFMine::Explode()
{
	UE_LOG(LogTemp, Log, TEXT("I HAZ BOOM MANUEL !"));
	Destroy();
}