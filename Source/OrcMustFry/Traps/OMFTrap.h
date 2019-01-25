// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericTeamAgentInterface.h"
#include "OMFTrap.generated.h"

UCLASS()
class ORCMUSTFRY_API AOMFTrap : public AActor, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOMFTrap();

	virtual void BeginPlay()override;
	
	//Methods
public:

	virtual bool CanAttack();

	virtual FGenericTeamId GetGenericTeamId() const override { return OMFTeamID; }
	void SetGenericTeamId(const FGenericTeamId& NewTeamID)override;

	int32 GetTrapSize();

	void ChangeBuildState(bool _CanBuild);

	//Attributes
public:

	UPROPERTY(Category = OMFTrap, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(Category = OMFTrap, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SceneComponent;

	UPROPERTY(Category = OMFTrap, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BuildTrigger;

	UPROPERTY(Category = "TeamID", EditAnywhere, BlueprintReadWrite)
	FGenericTeamId OMFTeamID;

	bool bIsActive;
};
