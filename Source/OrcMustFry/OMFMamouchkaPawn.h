// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "OMFMamouchkaPawn.generated.h"

DECLARE_DYNAMIC_DELEGATE(FManualTriggerDelegate);

UCLASS()
class ORCMUSTFRY_API AOMFMamouchkaPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AOMFMamouchkaPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Methods
public:
	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	UFUNCTION()
	void ManualTrigger();

	//Attributes
public:

	UPROPERTY(Category = OMFProjectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(Category = OMFProjectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UOMFProjectileComponent* ProjectileComponent;

	FManualTriggerDelegate ManualTriggerDel;

	//Attributes
protected:

	float ForwardValue;

	float RightValue;

	UPROPERTY(Category = Mamouchka, EditAnywhere)
	float RotationSpeed;
};
