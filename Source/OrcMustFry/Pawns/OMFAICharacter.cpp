// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFAICharacter.h"

#include "OMFAIController.h"
#include "OMFAIPerceptionComponent.h"

void AOMFAICharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AOMFAIController* CurrentController = Cast<AOMFAIController>(NewController);

	UAIPerceptionSystem* AIPerceptionSys = UAIPerceptionSystem::GetCurrent(GetWorld());

	if (nullptr != CurrentController && nullptr != CurrentController->PerceptionComponent && AIPerceptionSys != nullptr)
	{
		CurrentController->SetGenericTeamId(OMFTeamID);

		AIPerceptionSys->UpdateListener(*CurrentController->PerceptionComponent);
		
	}
}