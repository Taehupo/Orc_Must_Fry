// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OrcMustFryCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "OMFAttackComponent.h"
#include "OMFBuildingComponent.h"

//////////////////////////////////////////////////////////////////////////
// AOrcMustFryCharacter

AOrcMustFryCharacter::AOrcMustFryCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	bIsBuilding = false;

	BuildComponent = CreateDefaultSubobject<UOMFBuildingComponent>(TEXT("BuildComponent"));

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AOrcMustFryCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AOrcMustFryCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AOrcMustFryCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AOrcMustFryCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AOrcMustFryCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AOrcMustFryCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AOrcMustFryCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AOrcMustFryCharacter::OnResetVR);

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AOrcMustFryCharacter::Action);
	PlayerInputComponent->BindAction("Attack", IE_Released, AttackComponent, &UOMFAttackComponent::StopAttack);

	PlayerInputComponent->BindAction("AttackBis", IE_Pressed, AttackComponent, &UOMFAttackComponent::AttackBis);

	PlayerInputComponent->BindAxis("ChangeWeapon", this, &AOrcMustFryCharacter::ChangeDevice);
	PlayerInputComponent->BindAction("SwitchMode", IE_Pressed, this, &AOrcMustFryCharacter::SwitchMode);

}


void AOrcMustFryCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AOrcMustFryCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AOrcMustFryCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AOrcMustFryCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AOrcMustFryCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AOrcMustFryCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);

		if (bIsBuilding && nullptr != BuildComponent)
		{
			BuildComponent->CheckNewPos();
		}
	}
}

void AOrcMustFryCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);

		if (bIsBuilding && nullptr != BuildComponent)
		{
			BuildComponent->CheckNewPos();
		}

	}
}

void AOrcMustFryCharacter::SwitchMode()
{
	bIsBuilding = !bIsBuilding;

	if (nullptr != AttackComponent && nullptr != BuildComponent)
	{
		if (bIsBuilding)
		{
			AttackComponent->StopAttack();
			AttackComponent->DestroyWeapon();
			BuildComponent->ChangeCurrentTrap();
		}
		else
		{
			AttackComponent->ChangeCurrentWeapon();
			BuildComponent->DestroyTrap();
		}
	}
}

void AOrcMustFryCharacter::ChangeDevice(float Value)
{
	if (bIsBuilding && nullptr != BuildComponent)
	{
		BuildComponent->ChangeTrap(Value);
	}
	else if (nullptr != AttackComponent)
	{
		AttackComponent->ChangeWeapon(Value);
	}
}

void AOrcMustFryCharacter::Action()
{
	if (bIsBuilding && nullptr != BuildComponent)
	{
		BuildComponent->SetTrap();
	}
	else if (nullptr != AttackComponent)
	{
		AttackComponent->Attack();
	}
}

void AOrcMustFryCharacter::AddControllerYawInput(float Val)
{
	Super::AddControllerYawInput(Val);

	if (Val != 0.f && bIsBuilding && nullptr != BuildComponent)
	{
		BuildComponent->CheckNewPos();
	}
}

void AOrcMustFryCharacter::AddControllerRollInput(float Val)
{
	Super::AddControllerRollInput(Val);

	if (Val != 0.f && bIsBuilding && nullptr != BuildComponent)
	{
		BuildComponent->CheckNewPos();
	}
}