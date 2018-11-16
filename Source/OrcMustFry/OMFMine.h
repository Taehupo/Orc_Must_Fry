// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFProjectile.h"
#include "OMFMine.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFMine : public AOMFProjectile
{
	GENERATED_BODY()

public:
	AOMFMine();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Methods
public:

	virtual void InitProjectile(FVector Location, FVector ForwardWeapon);

	virtual void OnValidHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	
	
};
