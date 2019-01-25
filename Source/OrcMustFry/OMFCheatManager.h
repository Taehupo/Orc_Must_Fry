// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "OMFCharacter.h"
#include "OMFCheatManager.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API UOMFCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		TSubclassOf<AOMFCharacter> aiChar;

	UFUNCTION(exec)
		void SpawnAI(int32 spawnerIndex, int32 endIndex, int32 team);
	
};
