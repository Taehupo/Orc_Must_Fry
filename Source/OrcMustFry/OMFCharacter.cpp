// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFCharacter.h"
#include "OMFAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
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

void AOMFCharacter::PossessedBy(AController* newController)
{
	Super::PossessedBy(newController);

	AOMFAIController* test = Cast<AOMFAIController>(newController);

	if (nullptr != test)
	{
		OMFTeamId.SetAttitudeSolver(UUtilitaries::OMFAttitudeTeamSolver);
		
		test->SetGenericTeamId(OMFTeamId);		
	}

	UAIPerceptionSystem* AIPerceptionSys = UAIPerceptionSystem::GetCurrent(GetWorld());

	if (AIPerceptionSys != nullptr)
	{
		AIPerceptionSys->RegisterPerceptionStimuliSource(GetWorld(), UAISense_Sight::StaticClass(), this);
	}
}