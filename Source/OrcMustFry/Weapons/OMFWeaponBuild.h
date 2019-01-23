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

		int32 trapIndex;

		UPROPERTY(EditAnywhere, Category = Trap)
			TArray<TSubclassOf<AOMFTrap>> trapClasses;

		AOMFTrap* currentTrap;

protected:
	AOMFTrap * SpawnTrap();	

	UPROPERTY(EditAnywhere, Category = Trap)
		TEnumAsByte<EOMFTraps> currentTrapType;
	
};
