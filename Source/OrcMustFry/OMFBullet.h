// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFProjectile.h"
#include "OMFBullet.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFBullet : public AOMFProjectile
{
	GENERATED_BODY()

public:
	//Default Values for actor
	AOMFBullet();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Methods
public:

	virtual void InitProjectile(FVector Location, FVector ForwardWeapon);

	UFUNCTION()
		virtual void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	
	
};
