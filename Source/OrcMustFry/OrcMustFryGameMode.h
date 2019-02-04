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
	virtual void Tick(float DeltaTime) override;

	void StartNextWave();

	void EndWave();

	void SpawnAI(TSubclassOf<class AOMFAICharacter> aiChar, int32 spawnerIndex, int32 endIndex, int32 team);

	TArray<AOMFStartAI*> aiSpawnPoints;

	TArray<AOMFEndAI*> aiTargets;

	bool waveStarted;

	UPROPERTY(EditAnywhere)
	TArray<FOMFWave> waveList;

	int32 currentWaveIndex;
	int32 currentInWaveIndex;

	float waveTimer;

	float inWaveTimer;
};



