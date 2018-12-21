// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "OMFAIController.generated.h"

/**
 * (bDetectEnemies=True,bDetectNeutrals=True,bDetectFriendlies=True)
 */
UCLASS()
class ORCMUSTFRY_API AOMFAIController : public AAIController
{
	GENERATED_BODY()

public:
	AOMFAIController(const FObjectInitializer&);
	
};
