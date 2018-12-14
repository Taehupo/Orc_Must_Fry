// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFProjectile.h"
#include "OMFAOEProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFAOEProjectile : public AOMFProjectile
{
	GENERATED_BODY()
	
public:
	AOMFAOEProjectile();

	//Attributes
protected:

	UPROPERTY(Category = OMFProjectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* AOETrigger;
	
	
};
