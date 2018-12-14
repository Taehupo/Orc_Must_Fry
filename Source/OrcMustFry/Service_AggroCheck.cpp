// Fill out your copyright notice in the Description page of Project Settings.

#include "Service_AggroCheck.h"
#include "OMFCharacter.h"
#include "Engine/World.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIController.h"

void UService_AggroCheck::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AOMFCharacter * player = (AOMFCharacter *)UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	float distance = (OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation() - player->GetActorLocation()).Size();

	if (distance <= 2000.0f)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), player);
	}	

}