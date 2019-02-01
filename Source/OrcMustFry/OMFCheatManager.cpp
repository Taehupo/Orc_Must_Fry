// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFCheatManager.h"
#include "OrcMustFryGameMode.h"
#include "Classes/AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Engine.h"

void UOMFCheatManager::SpawnAI(int32 spawnerIndex, int32 endIndex, int32 team)
{
	AOrcMustFryGameMode* gameMode = Cast<AOrcMustFryGameMode>(GetWorld()->GetAuthGameMode());
	if (nullptr != gameMode)
	{
		FRotator rot = FRotator(0, 0, 0);
		AOMFCharacter * temp = GetWorld()->SpawnActor<AOMFCharacter>(aiChar->GetDefaultObject()->GetClass(),
			gameMode->aiSpawnPoints[spawnerIndex]->GetActorLocation(), rot);
		if (nullptr != temp)
		{
			temp->OMFTeamID = team;
			AAIController* test = Cast<AAIController>(temp->GetController());
				
			if (nullptr != test)
			{
				test->GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), gameMode->aiTargets[spawnerIndex]);
			}				
		}		
	}
	
}