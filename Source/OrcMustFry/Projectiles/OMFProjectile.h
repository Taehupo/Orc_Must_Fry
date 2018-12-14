// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OMFProjectile.generated.h"

DECLARE_DYNAMIC_DELEGATE(FProjectileLifeEnded);

UCLASS()
class ORCMUSTFRY_API AOMFProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOMFProjectile();

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
	
	UFUNCTION()
	virtual void OnProjectileHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	//virtual void OMFProjectileHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	virtual void OnLifeEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLifeEndedBP();

	virtual bool IsValidActorForCollision(AActor* _OtherActor);

	//Attributes
public:

	/*UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SceneComponent;*/

	UPROPERTY(Category = OMFProjectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(Category = OMFProjectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UOMFProjectileComponent* ProjectileComponent;

	FProjectileLifeEnded EndLifeDel;

	//Attributes
protected:

	UPROPERTY(Category = OMFProjectile, EditAnywhere)
	float OMFLifeSpan;

	FTimerHandle ProjectileTimerHandle;

};
