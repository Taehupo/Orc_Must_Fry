// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFAttackComponent.h"

#include "Weapons/OMFWeapon.h"
#include "OMFCharacter.h"
#include "Weapons/OMFWeaponBuild.h"
#include "Traps/OMFTrap.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMeshSocket.h"

// Sets default values for this component's properties
UOMFAttackComponent::UOMFAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	IndexWeapon = 0;
	TimeSinceLastAttack = 0.f;
}


// Called when the game starts
void UOMFAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	OwnerCharacter = Cast<AOMFCharacter>(GetOwner());

	ChangeCurrentWeapon();
}

void UOMFAttackComponent::InitializeComponent()
{
	Super::InitializeComponent();


}

// Called every frame
void UOMFAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (TimeSinceLastAttack > 0.f)
	{
		TimeSinceLastAttack -= DeltaTime;
	}
	else if (IsAttacking && nullptr != CurrentWeapon)
	{
		CurrentWeapon->Attack();
		TimeSinceLastAttack = CurrentWeapon->AttackSpeed;
		if (CurrentWeapon->SemiAuto)
			IsAttacking = false;
	}

	if (nullptr != OwnerCharacter && CurrentWeapon != nullptr && nullptr != OwnerCharacter->GetController())
	{
		CurrentWeapon->SetActorRotation(OwnerCharacter->GetControlRotation());
	}

}

void UOMFAttackComponent::Attack()
{
	IsAttacking = true;
}

void UOMFAttackComponent::StopAttack()
{
	IsAttacking = false;
}

void UOMFAttackComponent::ChangeWeapon(float Value)
{
	if (OwnerCharacter->state == EOMFPlayerState::ATTACKING)
	{
		if (Value == 0)
			return;

		if (Value > 0)
		{
			IndexWeapon += 1;
		}
		else
		{
			IndexWeapon -= 1;
		}

		if (IndexWeapon < 0)
		{
			IndexWeapon = WeaponClasses.Num() - 1;
		}

		if (IndexWeapon >= WeaponClasses.Num())
		{
			IndexWeapon = 0;
		}

		ChangeCurrentWeapon();
	}
	else if (OwnerCharacter->state == EOMFPlayerState::BUILDING)
	{
		if (Value == 0)
			return;

		AOMFWeaponBuild * weapon = Cast<AOMFWeaponBuild>(CurrentWeapon);

		if (nullptr != weapon)
		{
			if (Value > 0)
			{
				weapon->trapIndex += 1;
			}
			else
			{
				weapon->trapIndex -= 1;
			}

			if (weapon->trapIndex < 0)
			{
				weapon->trapIndex = weapon->trapClasses.Num() - 1;
			}

			if (weapon->trapIndex >= weapon->trapClasses.Num())
			{
				weapon->trapIndex = 0; 
			}

			ChangeCurrentTrap();
		}		
	}	
}

void UOMFAttackComponent::ChangeCurrentWeapon()
{
	if (nullptr != GetWorld() && WeaponClasses.Num() > IndexWeapon)
	{
		if (CurrentWeapon != nullptr )
			CurrentWeapon->Destroy();

		CurrentWeapon = GetWorld()->SpawnActor<AOMFWeapon>(WeaponClasses[IndexWeapon]);
		if (nullptr != CurrentWeapon && nullptr != CurrentWeapon->GetRootComponent() && nullptr != OwnerCharacter && nullptr != OwnerCharacter->GetMesh())
		{
			CurrentWeapon->GetRootComponent()->AttachTo(OwnerCharacter->GetMesh(), TEXT("WeaponSocket"), EAttachLocation::KeepRelativeOffset);
			CurrentWeapon->OwnerCharacter = OwnerCharacter;
			TimeSinceLastAttack = CurrentWeapon->AttackSpeed;
			if (CurrentWeapon->IsA<AOMFWeaponBuild>())
			{
				OwnerCharacter->state = EOMFPlayerState::BUILDING;
			}
		}
	}
}

void UOMFAttackComponent::ChangeCurrentTrap()
{
	AOMFWeaponBuild * weapon = Cast<AOMFWeaponBuild>(CurrentWeapon);


	if (nullptr != GetWorld() && nullptr != weapon && weapon->trapClasses.Num() > weapon->trapIndex)
	{
		if (weapon->currentTrap != nullptr)
			weapon->currentTrap->Destroy();

		weapon->currentTrap = GetWorld()->SpawnActor<AOMFTrap>(weapon->trapClasses[weapon->trapIndex]);
		weapon->currentTrap->MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void UOMFAttackComponent::AttackBis()
{
	if (nullptr != CurrentWeapon)
	{
		CurrentWeapon->AttackBis();
	}
}