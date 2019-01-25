// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFCharacter.h"
#include "OMFAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFAICharacter : public AOMFCharacter
{
	GENERATED_BODY()
	

public:

	virtual void PossessedBy(AController* NewController)override;
};
