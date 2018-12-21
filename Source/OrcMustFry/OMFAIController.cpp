// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFAIController.h"
#include "Perception/AIPerceptionComponent.h"

AOMFAIController::AOMFAIController(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("OMFPerceptionComponent"));
}