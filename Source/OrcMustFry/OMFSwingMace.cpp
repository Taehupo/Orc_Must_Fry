// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFSwingMace.h"

void AOMFSwingMace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (timer >= coolDown)
	{
		if (targetArray.Num() != 0)
		{
			UE_LOG(LogTemp, Log, TEXT("I IZ TAPER %d TINGS !"), targetArray.Num());
		}		
		timer = 0.0f;
	}
	timer += DeltaTime;
}

void AOMFSwingMace::InitTrap(FVector Location)
{
	timer = 0.0f;
}

void AOMFSwingMace::OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AOrcMustFryCharacter* temp = Cast<AOrcMustFryCharacter>(OtherActor);

	if (temp->IsA(AOrcMustFryCharacter::StaticClass()))
	{
		targetArray.Add(temp);
	}
}

void AOMFSwingMace::OnValidEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AOrcMustFryCharacter* temp = Cast<AOrcMustFryCharacter>(OtherActor);

	if (temp->IsA(AOrcMustFryCharacter::StaticClass()))
	{
		targetArray.Remove(temp);
	}
}
