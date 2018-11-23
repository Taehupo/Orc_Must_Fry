// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFSpikeTrap.h"

void AOMFSpikeTrap::OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("I HAZ OVERLAPPED ! I IZ SPIKY !"));
}
