// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBoomBarrel.h"
#include "OMFProjectile.h"

void AOMFBoomBarrel::OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//If the thing colliding exists, and it's a projectile, you explode
	if (nullptr != OtherActor && OtherActor->IsA<AOMFProjectile>())
	{
		UE_LOG(LogTemp, Log, TEXT("I HAZ BEEN HIT ! I EXPLOOOOOOOOODE *ded*"));
		Destroy();
	}
}
