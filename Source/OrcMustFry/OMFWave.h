// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OMFWave.generated.h"

USTRUCT()
struct FEnemySpawnData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AOMFAICharacter> EnemyType;

	UPROPERTY(EditAnywhere)
	int32 spawnIndex;

	UPROPERTY(EditAnywhere)
	int32 endIndex;

	UPROPERTY(EditAnywhere)
	float spawnTime;
};

USTRUCT()
struct ORCMUSTFRY_API FOMFWave
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TArray<FEnemySpawnData> WaveDataList;

	UPROPERTY(EditAnywhere)
	float WaveDuration;
};
