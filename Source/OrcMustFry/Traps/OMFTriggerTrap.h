// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFTrap.h"
#include "GenericTeamAgentInterface.h"
#include "OMFTriggerTrap.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFTriggerTrap : public AOMFTrap
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AOMFTriggerTrap();

protected:

	virtual void OnConstruction(const FTransform& Transform) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Methods
public:

	UFUNCTION()
	virtual void OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	virtual bool CanAttack();

	virtual void Attack();

	UFUNCTION(BlueprintImplementableEvent)
	void OnAttackBP();

	UFUNCTION()
	void ReloadFinished();

	void StartReload();

	//Attributes
protected:

	FTimerHandle ReloadedTimer;

	UPROPERTY(EditAnywhere, Category = Trap)
	float ReloadTime;

	UPROPERTY(Category = OMFProjectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USphereComponent* AOETrigger;

	bool bIsReloaded;

	bool bIsAttacking;

	int32 NbTargets;

	TArray<class AOMFCharacter*> OverlappedActors;
};
