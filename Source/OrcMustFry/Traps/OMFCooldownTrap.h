// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Traps/OMFTriggerTrap.h"
#include "OMFCooldownTrap.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFCooldownTrap : public AOMFTriggerTrap
{
	GENERATED_BODY()
	
	
	//Methods
public:
	virtual bool CanAttack();
	
};
