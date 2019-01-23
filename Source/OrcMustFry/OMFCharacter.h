// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "OMFTypes.h"
#include "OMFCharacter.generated.h"

UCLASS()
class ORCMUSTFRY_API AOMFCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AOMFCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual FGenericTeamId GetGenericTeamId() const override { return OMFTeamId; }

	void PossessedBy(AController* newController);

	//Methods
public:
	EOMFPlayerState state;
	//Attributes
protected:

	UPROPERTY(Category = "TeamID", EditAnywhere, BlueprintReadWrite)
	FGenericTeamId OMFTeamId;

	UPROPERTY(Category = OMFCharacter, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UOMFAttackComponent* AttackComponent;

	
};
