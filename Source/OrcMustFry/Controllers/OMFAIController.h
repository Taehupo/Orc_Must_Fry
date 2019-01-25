// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "OMFAIController.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFAIController : public AAIController
{
	GENERATED_BODY()

public:
	AOMFAIController(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;

	//TeamAgent
	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

public:

	//virtual void SetGenericTeamId(const FGenericTeamId& TeamID);
};
