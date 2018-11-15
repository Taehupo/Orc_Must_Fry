// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFAttackComponent.h"

#include "OMFWeapon.h"
#include "OMFCharacter.h"

#include "Engine/World.h"
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

	//Timer to manage Attackspeed (gatlings are fun, but too easy)
	if (TimeSinceLastAttack > 0.f)
	{
		TimeSinceLastAttack -= DeltaTime;
	}
	else if (IsAttacking && nullptr != CurrentWeapon)
	{
		CurrentWeapon->Attack();
		TimeSinceLastAttack = CurrentWeapon->AttackSpeed;
	}

	//Set weapon rotation to follow character orientation using SetActorRotation()
	if (nullptr != OwnerCharacter && CurrentWeapon != nullptr)
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

//Change weapon. Using a float because mousewheel gives float values on inputs
void UOMFAttackComponent::ChangeWeapon(float Value)
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


	//Just so you don't derp and try to have a weapon that doesn't exist
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

void UOMFAttackComponent::ChangeCurrentWeapon()
{
	//Do we have a world ? (Check tes pointeurs !)
	if (nullptr != GetWorld())
	{
		//Destroy weapon if you already have one
		if (CurrentWeapon != nullptr)
			CurrentWeapon->Destroy();

		//Spawn weapon (function gets a param to specify which class you need to spawn)
		CurrentWeapon = GetWorld()->SpawnActor<AOMFWeapon>(WeaponClasses[IndexWeapon]);
		if (nullptr != CurrentWeapon && nullptr != CurrentWeapon->GetRootComponent() && nullptr != OwnerCharacter && nullptr != OwnerCharacter->GetMesh())
		{
			//Attach weapon to owner (character) mesh via AttachTo() (Deprecated, better use AttachToActor()), 
			//EAttachLocation determines how the attached object will behave relative to new owner.
			CurrentWeapon->GetRootComponent()->AttachTo(OwnerCharacter->GetMesh(), TEXT("WeaponSocket"), EAttachLocation::KeepRelativeOffset);
			TimeSinceLastAttack = CurrentWeapon->AttackSpeed;
		}
	}
}