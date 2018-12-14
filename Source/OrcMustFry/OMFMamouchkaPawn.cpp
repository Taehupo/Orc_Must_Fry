// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFMamouchkaPawn.h"

#include "OMFProjectileComponent.h"

#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"

// Sets default values
AOMFMamouchkaPawn::AOMFMamouchkaPawn()
{
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	RootComponent = MeshComponent;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileComponent = CreateDefaultSubobject<UOMFProjectileComponent>(TEXT("ProjComponent"));

	ForwardValue = 0.f;
	RightValue = 0.f;

}

// Called when the game starts or when spawned
void AOMFMamouchkaPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOMFMamouchkaPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (nullptr != ProjectileComponent)
	{
		FVector NewForward = GetActorForwardVector();
		if (ForwardValue != 0.f)
		{
			SetActorRotation(FRotationMatrix::MakeFromX(NewForward.RotateAngleAxis((ForwardValue * DeltaTime * RotationSpeed * 180.f) / 3.14f, GetActorRightVector())).ToQuat());
			ProjectileComponent->Velocity = NewForward * ProjectileComponent->InitialSpeed;
		}

		if (RightValue != 0.f)
		{
			SetActorRotation(FRotationMatrix::MakeFromX(NewForward.RotateAngleAxis((RightValue * DeltaTime * RotationSpeed * 180.f) / 3.14f, GetActorUpVector())).ToQuat());
			ProjectileComponent->Velocity = NewForward * ProjectileComponent->InitialSpeed;
		}
		
		
	}

}

// Called to bind functionality to input
void AOMFMamouchkaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AOMFMamouchkaPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AOMFMamouchkaPawn::MoveRight);

	PlayerInputComponent->BindAction("AttackBis", IE_Pressed, this, &AOMFMamouchkaPawn::ManualTrigger);

}

void AOMFMamouchkaPawn::MoveForward(float Value)
{
	ForwardValue = Value;
}

void AOMFMamouchkaPawn::MoveRight(float Value)
{
	RightValue = Value;
}

void AOMFMamouchkaPawn::ManualTrigger()
{
	ManualTriggerDel.ExecuteIfBound();
}