// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OrcMustFryGameMode.h"
#include "OrcMustFryCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"

AOrcMustFryGameMode::AOrcMustFryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}	
}

void AOrcMustFryGameMode::BeginPlay()
{
	Super::BeginPlay();

	for (TActorIterator<AOMFStartAI> ActorItr(GetWorld()) ; ActorItr; ++ActorItr)
	{
		aiSpawnPoints.Add(*ActorItr);
	}

	for (TActorIterator<AOMFEndAI> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		aiTargets.Add(*ActorItr);
	}
}
