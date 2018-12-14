// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OMFAOEProjectile.h"
#include "OMFMamouchka.generated.h"

/**
 * 
 */
UCLASS()
class ORCMUSTFRY_API AOMFMamouchka : public AOMFAOEProjectile
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;
	
	//Methods
public:
	virtual void InitProjectile(FVector Location, FVector ForwardWeapon);

	virtual void OnLifeEnded();

	UFUNCTION()
	void OnPawnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);


	//Attributes
public:

	class AOMFMamouchkaPawn* CurrentMamouchkaPawn;

	//Attributes
protected:
	
	UPROPERTY(Category = Mamouchka, EditAnywhere)
	TSubclassOf<class AOMFMamouchkaPawn> MamouchkaPawnClass;

	
};
