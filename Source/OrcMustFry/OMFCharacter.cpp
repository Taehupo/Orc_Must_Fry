// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFCharacter.h"

#include "OMFAttackComponent.h"

#include "GenericTeamAgentInterface.h"

#include "Perception/AIPerceptionSystem.h"
#include "Perception/AISense_Sight.h"


// Sets default values
AOMFCharacter::AOMFCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackComponent = CreateDefaultSubobject<UOMFAttackComponent>(TEXT("AttackComponent"));

}

void AOMFCharacter::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
}

// Called when the game starts or when spawned
void AOMFCharacter::BeginPlay()
{
	Super::BeginPlay();	
}

void AOMFCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	OMFTeamID.SetAttitudeSolver(&OMFTeamAttitudeSolver);

	UAIPerceptionSystem* AIPerceptionSys = UAIPerceptionSystem::GetCurrent(GetWorld());

	if (AIPerceptionSys != nullptr)
	{
		AIPerceptionSys->RegisterPerceptionStimuliSource(GetWorld(), UAISense_Sight::StaticClass(), this);
	}
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

void AOMFCharacter::Attack()
{
	if (nullptr != AttackComponent)
	{
		AttackComponent->Attack();
	}
}