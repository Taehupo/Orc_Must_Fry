// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBuildingComponent.h"

#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "DrawDebugHelpers.h"
#include "NavigationSystem.h"

#include "OMFTrap.h"
#include "OMFCharacter.h"

// Sets default values for this component's properties
UOMFBuildingComponent::UOMFBuildingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	CanBuild = false;
}


// Called when the game starts
void UOMFBuildingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	OwnerCharacter = Cast<AOMFCharacter>(GetOwner());

}


// Called every frame
void UOMFBuildingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UOMFBuildingComponent::ChangeTrap(float Value)
{
	if (Value == 0)
		return;

	if (Value > 0)
	{
		IndexTrap += 1;
	}
	else
	{
		IndexTrap -= 1;
	}

	if (IndexTrap < 0)
	{
		IndexTrap = TrapClasses.Num() - 1;
	}

	if (IndexTrap >= TrapClasses.Num())
	{
		IndexTrap = 0;
	}

	ChangeCurrentTrap();
}

void UOMFBuildingComponent::ChangeCurrentTrap()
{
	if (nullptr != GetWorld() && TrapClasses.Num() > IndexTrap)
	{
		DestroyTrap();

		CurrentTrap = GetWorld()->SpawnActorDeferred<AOMFTrap>(TrapClasses[IndexTrap], FTransform());

		if (nullptr != CurrentTrap)
		{
			CurrentTrap->SetGenericTeamId(OwnerCharacter->GetGenericTeamId());
			CurrentTrap->MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			CurrentTrap->bIsActive = false;
			CurrentTrap->FinishSpawning(FTransform());
			CheckNewPos();
			CanBuild = false;
			ChangeBuildState();
		}
	}
}

void UOMFBuildingComponent::DestroyTrap()
{
	if (CurrentTrap != nullptr)
	{
		CurrentTrap->Destroy();
		CurrentTrap = nullptr;
	}
}

void UOMFBuildingComponent::SetTrap()
{
	if (nullptr != GetWorld() && nullptr != CurrentTrap && CanBuild)
	{
		AOMFTrap* TempTrap = GetWorld()->SpawnActorDeferred<AOMFTrap>(CurrentTrap->GetClass(), CurrentTrap->GetTransform());

		if (nullptr != TempTrap)
		{
			TempTrap->SetGenericTeamId(OwnerCharacter->GetGenericTeamId());
			TempTrap->FinishSpawning(CurrentTrap->GetTransform());
			CheckNewPos();
		}
	}
}

void UOMFBuildingComponent::CheckNewPos()
{
	if (nullptr != OwnerCharacter)
	{
		FVector StartLocation = OwnerCharacter->GetActorLocation();
		FVector EndRayCast = StartLocation + (OwnerCharacter->GetControlRotation().Vector() * 1000.f);
		TArray<FHitResult> ResultHit;

		if (nullptr != GetWorld() && nullptr != CurrentTrap)
		{
			FCollisionQueryParams QueryParams;

			GetWorld()->LineTraceMultiByChannel(ResultHit, StartLocation, EndRayCast, ECollisionChannel::ECC_Visibility, QueryParams);

			DrawDebugLine(GetWorld(), StartLocation, EndRayCast, FColor::Green);

			for (auto Hit : ResultHit)
			{
				if (Hit.bBlockingHit && nullptr != Hit.GetActor() && Hit.GetActor()->ActorHasTag(TEXT("TrapGround")))
				{
					FVector PosGrid = Hit.ImpactPoint;
					PosGrid.Z = OwnerCharacter->GetActorLocation().Z - OwnerCharacter->GetDefaultHalfHeight();
					PosGrid.X = (int32)(PosGrid.X / (CurrentTrap->GetTrapSize())) * CurrentTrap->GetTrapSize();
					PosGrid.Y = (int32)(PosGrid.Y / (CurrentTrap->GetTrapSize())) * CurrentTrap->GetTrapSize();

					CurrentTrap->SetActorLocation(PosGrid);

					if (CanBuildTrap() != CanBuild)
					{
						CanBuild = !CanBuild;
						ChangeBuildState();
						//CurrentTrap->ChangeBuildState(CanBuild);
					}
				}
			}
		}
	}
}

void UOMFBuildingComponent::ChangeBuildState()
{
	if (nullptr != CurrentTrap && nullptr != CurrentTrap->MeshComponent && nullptr != OwnerCharacter)
	{
		UMaterialInstanceDynamic* MatDyn = CurrentTrap->MeshComponent->CreateAndSetMaterialInstanceDynamic(0);

		if (nullptr != MatDyn)
		{
			MatDyn->SetScalarParameterValue("Opacity", OwnerCharacter->OpacityValue);
			MatDyn->SetVectorParameterValue("Color", CanBuild ? FLinearColor(OwnerCharacter->BuildColor): FLinearColor(OwnerCharacter->NoBuildColor));
		}
	}
}

bool UOMFBuildingComponent::CanBuildTrap()
{
	TArray<FOverlapInfo> AllOverlaps = CurrentTrap->BuildTrigger->GetOverlapInfos();

	for (auto Overlap : AllOverlaps)
	{
		if (Overlap.OverlapInfo.Actor.Get() != CurrentTrap)
		{
			return false;
		}
	}
	return true;
}