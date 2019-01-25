// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
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
	virtual void OnConstruction(const FTransform& Transform) override;

	virtual void PossessedBy(AController* NewController) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = OMFCharacter)
	void Attack();

	//Methods

public:
	virtual FGenericTeamId GetGenericTeamId() const override { return OMFTeamID; }


	//Attributes
public:
	UPROPERTY(EditAnywhere, Category = OMFAttack)
		float OpacityValue;

	UPROPERTY(EditAnywhere, Category = OMFAttack)
		FColor BuildColor;

	UPROPERTY(EditAnywhere, Category = OMFAttack)
		FColor NoBuildColor;

	UPROPERTY(Category = TeamID, EditAnywhere, BlueprintReadWrite)
		FGenericTeamId OMFTeamID;
	

	//Attributes
protected:		

	UPROPERTY(Category = OMFCharacter, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UOMFAttackComponent* AttackComponent;

	
};
