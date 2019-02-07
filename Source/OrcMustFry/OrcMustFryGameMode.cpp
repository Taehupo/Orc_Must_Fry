// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OrcMustFryGameMode.h"
#include "OrcMustFryCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Classes/AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Pawns/OMFAICharacter.h"
#include "EngineUtils.h"

AOrcMustFryGameMode::AOrcMustFryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	PrimaryActorTick.bStartWithTickEnabled = true;
	PrimaryActorTick.bCanEverTick = true;
}

void AOrcMustFryGameMode::BeginPlay()
{
	Super::BeginPlay();

	currentWaveIndex = 0;

	for (TActorIterator<AOMFStartAI> ActorItr(GetWorld()) ; ActorItr; ++ActorItr)
	{
		aiSpawnPoints.Add(*ActorItr);
	}

	for (TActorIterator<AOMFEndAI> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		aiTargets.Add(*ActorItr);
	}
}

void AOrcMustFryGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	waveTimer += DeltaTime;

	if (currentWaveIndex < waveList.Num())
	{
		if (waveTimer >= waveList[currentWaveIndex].WaveDuration && !waveStarted)
		{
			StartNextWave();
		}
	}	

	if (waveStarted)
	{
		inWaveTimer += DeltaTime;
					
			if (currentInWaveIndex < waveList[currentWaveIndex].WaveDataList.Num())
			{
				if (waveList[currentWaveIndex].WaveDataList[currentInWaveIndex].spawnTime <= inWaveTimer)
				{
					SpawnAI(waveList[currentWaveIndex].WaveDataList[currentInWaveIndex].EnemyType,
						waveList[currentWaveIndex].WaveDataList[currentInWaveIndex].spawnIndex,
						waveList[currentWaveIndex].WaveDataList[currentInWaveIndex].endIndex, 1);
					currentInWaveIndex++;
				}
			}
			else
			{
				EndWave();
			}
	}
}

void AOrcMustFryGameMode::StartNextWave()
{
	UE_LOG(LogTemp, Log, TEXT("Starting Wave number %d"), currentWaveIndex);
	waveStarted = true;
	inWaveTimer = 0;
	currentInWaveIndex = 0;
}

void AOrcMustFryGameMode::EndWave()
{
	waveTimer = 0;
	waveStarted = false;
	if (currentWaveIndex < waveList.Num())
	{
		++currentWaveIndex;
	}	
}

void AOrcMustFryGameMode::SpawnAI(TSubclassOf<AOMFAICharacter> aiChar,int32 spawnerIndex, int32 endIndex, int32 team)
{
	AOrcMustFryGameMode* gameMode = Cast<AOrcMustFryGameMode>(GetWorld()->GetAuthGameMode());
	if (nullptr != gameMode)
	{
		FRotator rot = FRotator(0, 0, 0);
		AOMFAICharacter * temp = GetWorld()->SpawnActor<AOMFAICharacter>(aiChar->GetDefaultObject()->GetClass(),
			gameMode->aiSpawnPoints[spawnerIndex]->GetActorLocation(), rot);
		if (nullptr != temp)
		{
			temp->SetGenericTeamId(team);
			AAIController* test = Cast<AAIController>(temp->GetController());

			if (nullptr != test)
			{
				test->GetBlackboardComponent()->SetValueAsObject(TEXT("EndTarget"), gameMode->aiTargets[endIndex]);
			}
		}
	}

}