// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericTeamAgentInterface.h"
#include "OMFWeapon.generated.h"

UCLASS()
class ORCMUSTFRY_API AOMFWeapon : public AActor, public IGenericTeamAgentInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOMFWeapon();

	virtual FGenericTeamId GetGenericTeamId() const override { return OMFTeamId; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = "TeamID", EditAnywhere, BlueprintReadWrite)
		FGenericTeamId OMFTeamId;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	

	//Methods
public:

	virtual void Attack();

	virtual void AttackBis();

	UFUNCTION(BlueprintImplementableEvent)
		void OnAttackBP();

	//Attributes
public:

	UPROPERTY(Category = OMFWeapon, EditAnywhere)
	float AttackSpeed;

	UPROPERTY(Category = OMFWeapon, EditAnywhere)
	bool SemiAuto;


	class AOMFCharacter* OwnerCharacter;

	//Attributes
protected:

	UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SceneComponent;

	UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComponent;
	
	
};
