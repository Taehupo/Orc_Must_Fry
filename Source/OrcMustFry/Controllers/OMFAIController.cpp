// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFAIController.h"
#include "OMFAIPerceptionComponent.h"
#include "OMFCharacter.h"

AOMFAIController::AOMFAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PerceptionComponent = CreateDefaultSubobject<UOMFAIPerceptionComponent>("OMFPerceptionComp");
}

void AOMFAIController::BeginPlay()
{
	Super::BeginPlay();
}

ETeamAttitude::Type AOMFAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	return Super::GetTeamAttitudeTowards(Other);

	/*const AOMFCharacter* OtherChar = Cast<AOMFCharacter>(&Other);

	if (nullptr != OtherChar && OtherChar->GetTeam() == GetCharTeam())
	{
		return ETeamAttitude::Friendly;
	}

	return ETeamAttitude::Hostile;*/
}

//void AOMFAIController::SetGenericTeamId(const FGenericTeamId& TeamID)
//{
//
//}