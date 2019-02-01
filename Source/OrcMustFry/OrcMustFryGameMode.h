// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OMFStartAI.h"
#include "OMFEndAI.h"
#include "OMFWave.h"
#include "OrcMustFryGameMode.generated.h"

UCLASS(minimalapi)
class AOrcMustFryGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOrcMustFryGameMode();

	virtual void BeginPlay() override;

	TArray<AOMFStartAI*> aiSpawnPoints;

	TArray<AOMFEndAI*> aiTargets;

	UPROPERTY(EditAnywhere)
	TArray<FOMFWave> waveList;
};



