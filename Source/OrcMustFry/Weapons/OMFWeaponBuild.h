// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/OMFWeapon.h"
#include "OMFTrap.h"
#include "OMFTypes.h"
#include "OMFWeaponBuild.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFWeaponBuild : public AOMFWeapon
{
	GENERATED_BODY()

public:
	AOMFWeaponBuild();

public:
		virtual void BeginPlay();

		virtual void Attack();

		virtual void Tick(float DeltaTime) override;

protected:
	AOMFTrap * SpawnTrap();

	AOMFTrap* currentTrap;

	UPROPERTY(EditAnywhere, Category = Trap)
		TEnumAsByte<EOMFTraps> currentTrapType;

	UPROPERTY(EditAnywhere, Category = Trap)
		TArray<TSubclassOf<AOMFTrap>> trapClasses;

	int32 trapIndex;
	
};
