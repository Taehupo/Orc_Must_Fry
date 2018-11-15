// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OMFTypes.h"
#include "OMFAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ORCMUSTFRY_API UOMFAttackComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOMFAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void InitializeComponent() override;
		
	//Methods
public:

	void Attack();
	void StopAttack();

	void ChangeWeapon(float Value);

	void ChangeCurrentWeapon();

	//Attributes
protected:

	class AOMFCharacter* OwnerCharacter;

	class AOMFWeapon* CurrentWeapon;

	UPROPERTY(EditAnywhere, Category = OMFAttack)
	TEnumAsByte<enum EOMFWeapon> CurrentWeaponType;

	int32 IndexWeapon;

	UPROPERTY(EditAnywhere, Category = OMFAttack)
	TArray< TSubclassOf<class AOMFWeapon>> WeaponClasses;

	bool IsAttacking;

	float TimeSinceLastAttack;

};
