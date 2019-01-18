// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericTeamAgentInterface.h"
#include "OMFTypes.h"
#include "OMFProjectile.generated.h"

/*ETeamAttitude::Type OMFTeamAttitudeSolver(FGenericTeamId A, FGenericTeamId B)
{
	return A.GetId() != B.GetId() ? ETeamAttitude::Hostile : ETeamAttitude::Friendly;
}

FGenericTeamId::FAttitudeSolverFunction* OMFAttitudeTeamSolver = &OMFTeamAttitudeSolver;*/

DECLARE_DYNAMIC_DELEGATE(FProjectileLifeEnded);

UCLASS()
class ORCMUSTFRY_API AOMFProjectile : public AActor, public IGenericTeamAgentInterface
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

	virtual void InitProjectile(FVector Location, FVector ForwardWeapon, FGenericTeamId Team);
	
	UFUNCTION()
	virtual void OnProjectileHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	//virtual void OMFProjectileHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	virtual void OnLifeEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLifeEndedBP();

	virtual bool IsValidActorForCollision(AActor* _OtherActor);

	virtual FGenericTeamId GetGenericTeamId() const override { return OMFTeamId; }

	//Attributes
public:

	/*UPROPERTY(Category = OMFWeapon, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SceneComponent;*/

	UPROPERTY(Category = OMFProjectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* MeshComponent;

	UPROPERTY(Category = OMFProjectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UOMFProjectileComponent* ProjectileComponent;

	FProjectileLifeEnded EndLifeDel;

	FGenericTeamId OMFTeamId;

	//Attributes
protected:

	UPROPERTY(Category = OMFProjectile, EditAnywhere)
	float OMFLifeSpan;

	FTimerHandle ProjectileTimerHandle;

};
