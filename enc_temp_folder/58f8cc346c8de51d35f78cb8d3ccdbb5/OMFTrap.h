// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OMFTrap.generated.h"

UCLASS()
class ORCMUSTFRY_API AOMFTrap : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOMFTrap();

	//Methods
public:

	virtual bool CanAttack();

	//Attributes
public:

	UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* SceneComponent;
};
