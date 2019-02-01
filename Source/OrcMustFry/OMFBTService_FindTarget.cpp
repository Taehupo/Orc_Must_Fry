// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBTService_FindTarget.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISense_Sight.h"

#include "OMFCharacter.h"
#include "OMFAIController.h"
#include "OMFAIPerceptionComponent.h"

void UOMFBTService_FindTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AActor* PlayerChar = nullptr;

	AOMFAIController* MyController = Cast<AOMFAIController>(OwnerComp.GetAIOwner());
	
	if (nullptr != MyController)
	{
		UOMFAIPerceptionComponent* PercComp = Cast<UOMFAIPerceptionComponent>(MyController->GetPerceptionComponent());

		float Distance = -1;

		if (nullptr != PercComp)
		{
			TArray<AActor*> PerceivedActors;
			PercComp->GetPerceivedActors(UAISense_Sight::StaticClass(), PerceivedActors);
			AOMFCharacter* MyChar = Cast<AOMFCharacter>(MyController->GetPawn());
			for (auto MyActor : PerceivedActors)
			{
				if (nullptr != MyActor && nullptr != MyChar)
				{
					Distance = MyActor->GetDistanceTo(MyChar);
					PlayerChar = MyActor;
				}
			}
		}
		
		UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();
		if (nullptr != BBComp)
		{
			if (Distance > -1 && Distance < 300.f)
			{

				BBComp->SetValueAsBool(TEXT("HasTarget"), true);
				BBComp->SetValueAsObject(TEXT("Target"), PlayerChar);
			}
			else
			{
				BBComp->SetValueAsBool(TEXT("HasTarget"), false);
				BBComp->SetValueAsObject(TEXT("Target"), PlayerChar);
			}
		}

	}

}