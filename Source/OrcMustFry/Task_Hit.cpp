// Fill out your copyright notice in the Description page of Project Settings.

#include "Task_Hit.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"
#include "OMFAttackComponent.h"

EBTNodeResult::Type UTask_Hit::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Log, TEXT("I IZ ATTACKING"));

	UOMFAttackComponent* temp = (UOMFAttackComponent*)(OwnerComp.GetAIOwner()->GetPawn()->GetComponentByClass(UOMFAttackComponent::StaticClass()));

	if (nullptr != temp)
	{
		temp->Attack();

		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::Failed;
	}
	
}