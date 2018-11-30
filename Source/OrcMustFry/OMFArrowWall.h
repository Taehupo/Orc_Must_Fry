// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTrap.h"
#include "OMFArrowWall.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFArrowWall : public AOMFTrap
{
	GENERATED_BODY()

	bool isShooting;

	UPROPERTY(VisibleAnywhere, Category = OMFTrap)
	int32 nbProjectileShot;

	UPROPERTY(EditAnywhere, Category = OMFTrap)
	float cooldown = 1.5f;

	float timer = cooldown;

public:
	UPROPERTY(EditAnywhere, Category = OMFTrap)
	int32 nbProjectileToShoot;

protected:
	UPROPERTY(EditAnywhere, Category = OMFTrap)
	TSubclassOf<class AOMFProjectile> ProjectileClass;
	
public:

	virtual void Tick(float DeltaTime) override;

	virtual void OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnValidEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
