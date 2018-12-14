// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFMamouchka.h"

#include "OMFMamouchkaPawn.h"

#include "Components/StaticMeshComponent.h"

#include "OMFProjectileComponent.h"

#include "Engine/World.h"

void AOMFMamouchka::BeginPlay()
{
	Super::BeginPlay();
}

void AOMFMamouchka::InitProjectile(FVector Location, FVector ForwardWeapon)
{
	CurrentMamouchkaPawn = GetWorld()->SpawnActor<AOMFMamouchkaPawn>(MamouchkaPawnClass);

	if (nullptr != CurrentMamouchkaPawn && nullptr != CurrentMamouchkaPawn->ProjectileComponent)
	{
		FRotator Rotation = FRotationMatrix::MakeFromX(ForwardWeapon).Rotator();
		SetActorLocation(Location);
		CurrentMamouchkaPawn->SetActorLocationAndRotation(Location,FRotationMatrix::MakeFromX(ForwardWeapon).ToQuat());
		CurrentMamouchkaPawn->ProjectileComponent->Velocity = ForwardWeapon * CurrentMamouchkaPawn->ProjectileComponent->InitialSpeed;
		if (nullptr != CurrentMamouchkaPawn->MeshComponent)
		{
			CurrentMamouchkaPawn->MeshComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &AOMFMamouchka::OnPawnOverlap);
		}
		CurrentMamouchkaPawn->ManualTriggerDel.BindDynamic(this, &AOMFMamouchka::OnLifeEnded);
		AttachToActor(CurrentMamouchkaPawn,FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("MamouchkaPawn spawned "));
	}
}

void AOMFMamouchka::OnLifeEnded()
{
	Super::OnLifeEnded();
	CurrentMamouchkaPawn->Destroy();
}

void AOMFMamouchka::OnPawnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	OnLifeEnded();
}