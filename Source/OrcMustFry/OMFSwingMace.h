// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTrap.h"
#include "OrcMustFryCharacter.h"
#include "OMFSwingMace.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFSwingMace : public AOMFTrap
{
	GENERATED_BODY()
	
public:
	virtual void InitTrap(FVector Location);

	virtual void Tick(float DeltaTime) override;

	virtual void OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnValidEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:

	TArray<AOrcMustFryCharacter*> targetArray;

	UPROPERTY(Category = OMFSwingMace, EditAnywhere)
	float coolDown;

	float timer;
	
};
