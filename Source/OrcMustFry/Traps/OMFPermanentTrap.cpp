// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFPermanentTrap.h"

#include "OMFCharacter.h"

AOMFPermanentTrap::AOMFPermanentTrap()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AOMFPermanentTrap::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AOMFCharacter* OtherChar = Cast<AOMFCharacter>(OtherActor);

	if (nullptr != OtherChar && OMFTeamAttitudeSolver(GetGenericTeamId(), OtherChar->GetGenericTeamId()) == ETeamAttitude::Hostile)
	{
		Attack();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Coucou AOMFPermanentTrap"));
	}
}

void AOMFPermanentTrap::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AOMFCharacter* OtherChar = Cast<AOMFCharacter>(OtherActor);

	if (nullptr != OtherChar && OMFTeamAttitudeSolver(GetGenericTeamId(), OtherChar->GetGenericTeamId()) == ETeamAttitude::Hostile)
	{
		FinishAttack();
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Byebye AOMFPermanentTrap"));
	}
}

void AOMFPermanentTrap::FinishAttack()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Actor : %s FinishAttack"), *GetNameSafe(this)));
}