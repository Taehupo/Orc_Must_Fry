// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OMFBuildingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ORCMUSTFRY_API UOMFBuildingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOMFBuildingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Methods
public:
	void ChangeTrap(float Value);

	void ChangeCurrentTrap();

	void DestroyTrap();

	void SetTrap();

	void CheckNewPos();

	void ChangeBuildState();

	bool CanBuildTrap();

	//Attributes
protected:

	class AOMFCharacter* OwnerCharacter;

	int32 IndexTrap;

	UPROPERTY(EditAnywhere, Category = OMFAttack)
	TArray< TSubclassOf<class AOMFTrap>> TrapClasses;

	class AOMFTrap* CurrentTrap;

	bool CanBuild;
};
