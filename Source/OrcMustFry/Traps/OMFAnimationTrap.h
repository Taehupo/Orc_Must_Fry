// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTrap.h"
#include "OMFAnimationTrap.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFAnimationTrap : public AOMFTrap
{
	GENERATED_BODY()

public:
		AOMFAnimationTrap();

		virtual void OnConstruction(const FTransform& Transform) override;

		// Called when the game starts or when spawned
		virtual void BeginPlay() override;

	//Methods
public:

	UFUNCTION()
	void OnMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);


	//Attributes
protected:

	UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshAnimated;
};
