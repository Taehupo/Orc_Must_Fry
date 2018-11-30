// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFSwingMace.h"

void AOMFSwingMace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Manual timer here too. It's just out of habit. TimerHandler will work great too. I will not stop putting manual timer though
	if (timer >= coolDown)
	{
		//If I have target registered at that exact time, I hurt them
		if (targetArray.Num() != 0)
		{
			UE_LOG(LogTemp, Log, TEXT("I IZ TAPER %d TINGS !"), targetArray.Num());
		}		
		timer = 0.0f;
	}
	timer += DeltaTime;
}

//I could do it somewhere else, but I can't be asked
void AOMFSwingMace::InitTrap(FVector Location)
{
	timer = 0.0f;
}

void AOMFSwingMace::OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//If you exist, and you are a Character, you register yourself to take damage
	if (nullptr != OtherActor && OtherActor->IsA<AOrcMustFryCharacter>())
	{
		targetArray.Add(Cast<AOrcMustFryCharacter>(OtherActor));
	}
}

void AOMFSwingMace::OnValidEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//If you exist, and you are a Character, you sign out of taking damage
	if (nullptr != OtherActor && OtherActor->IsA<AOrcMustFryCharacter>())
	{
		targetArray.Remove(Cast<AOrcMustFryCharacter>(OtherActor));
	}
}
