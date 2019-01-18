// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTypes.h"
#include "OMFWeapon.h"
#include "OMFWeaponMelee.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFWeaponMelee : public AOMFWeapon
{
	GENERATED_BODY()

public:

	AOMFWeaponMelee();

	virtual void BeginPlay();

	//Methods
public:

	virtual void Attack();

	//Attributes
protected:

	/*UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UActorSequenceComponent* AttackAnimation;*/

};
