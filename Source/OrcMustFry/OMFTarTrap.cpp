// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFTarTrap.h"

void AOMFTarTrap::OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("I HAZ OVERLAPPED ! I IZ SOLWING OF YUO !"));
}

void AOMFTarTrap::OnValidEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Log, TEXT("I HAZ FINISHED OVERLAPPING !!! I IZ NOT SOLWING OF YUO ANYMORE !"));
}