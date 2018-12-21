// Fill out your copyright notice in the Description page of Project Settings.

#include "Service_AggroCheck.h"
#include "OMFCharacter.h"
#include "Engine/World.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"
#include "OMFAIController.h"

void UService_AggroCheck::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AOMFCharacter * player = nullptr;

	AOMFAIController* myController = (AOMFAIController*)(OwnerComp.GetAIOwner());
	AOMFCharacter* AIChar = (AOMFCharacter*)OwnerComp.GetAIOwner()->GetPawn();
	float distance;

		if (nullptr != AIChar)
		{
			UAIPerceptionComponent* pComp = myController->GetPerceptionComponent();

			if (nullptr != pComp)
			{
				TArray<AActor*> percievedActors;

				pComp->GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(), percievedActors);

				for (AActor* actor : percievedActors)
				{
					player = Cast<AOMFCharacter>(actor);
					if (nullptr != player)
					{
						distance = (AIChar->GetDistanceTo(player));						
					}
				}
			}			
		}

		if (distance <= 2000.0f)
		{
			UBlackboardComponent * BBComp = OwnerComp.GetBlackboardComponent();
			if (nullptr != BBComp)
			{
				BBComp->SetValueAsObject(TEXT("Target"), player);
			}
		}
}