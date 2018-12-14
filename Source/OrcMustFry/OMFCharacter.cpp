// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFCharacter.h"

#include "OMFAttackComponent.h"


// Sets default values
AOMFCharacter::AOMFCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackComponent = CreateDefaultSubobject<UOMFAttackComponent>(TEXT("AttackComponent"));

}

// Called when the game starts or when spawned
void AOMFCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOMFCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOMFCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

