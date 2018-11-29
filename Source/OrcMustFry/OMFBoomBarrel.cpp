// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBoomBarrel.h"
#include "OMFProjectile.h"

void AOMFBoomBarrel::OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AOMFProjectile* temp = Cast<AOMFProjectile>(OtherActor);

	if (temp->IsA(AOMFProjectile::StaticClass()))
	{
		UE_LOG(LogTemp, Log, TEXT("I HAZ BEEN HIT ! I EXPLOOOOOOOOODE"));
	}
}
