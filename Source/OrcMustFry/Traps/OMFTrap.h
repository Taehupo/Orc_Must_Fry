// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericTeamAgentInterface.h"
#include "OMFTrap.generated.h"

ETeamAttitude::Type OMFTeamAttitudeSolver(FGenericTeamId A, FGenericTeamId B)
{
	return A.GetId() != B.GetId() ? ETeamAttitude::Hostile : ETeamAttitude::Friendly;
}

FGenericTeamId::FAttitudeSolverFunction* OMFAttitudeTeamSolver = &OMFTeamAttitudeSolver;

UCLASS()
class ORCMUSTFRY_API AOMFTrap : public AActor, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOMFTrap();

	//Methods
public:

	virtual bool CanAttack();

	virtual FGenericTeamId GetGenericTeamId() const override { return OMFTeamId; }

	//Attributes
public:

	UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* MeshComponent;

	UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* SceneComponent;

	UPROPERTY(Category = "TeamID", EditAnywhere, BlueprintReadWrite)
		FGenericTeamId OMFTeamId;
};
