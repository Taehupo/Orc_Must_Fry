// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFTriggerTrap.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "OMFCharacter.h"

// Sets default values
AOMFTriggerTrap::AOMFTriggerTrap()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AOETrigger = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));

	AOETrigger->SetupAttachment(RootComponent);

	NbTargets = 0;

	ReloadTime = 1.f;
}

void AOMFTriggerTrap::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	/*if (nullptr != MeshComponent && nullptr != AOETrigger)
	{
		AOETrigger->AttachToComponent(MeshComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepWorld, false));
	}*/
}

// Called when the game starts or when spawned
void AOMFTriggerTrap::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != AOETrigger)
	{
		AOETrigger->OnComponentBeginOverlap.AddUniqueDynamic(this, &AOMFTriggerTrap::OnTriggerBeginOverlap);
		AOETrigger->OnComponentEndOverlap.AddUniqueDynamic(this, &AOMFTriggerTrap::OnTriggerEndOverlap);
	}

	StartReload();
}

// Called every frame
void AOMFTriggerTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CanAttack())
	{
		Attack();
		StartReload();
	}
}

void AOMFTriggerTrap::StartReload()
{
	if (ReloadTime != 0.f)
	{
		GetWorld()->GetTimerManager().SetTimer(ReloadedTimer, this, &AOMFTriggerTrap::ReloadFinished, ReloadTime, false);
		bIsReloaded = false;
	}
}

bool AOMFTriggerTrap::CanAttack()
{
	return OverlappedActors.Num() > 0 && bIsReloaded;
}


void AOMFTriggerTrap::Attack()
{
	for (auto CurrentTarget : OverlappedActors)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Actor : %s Attack actor : %s"), *GetNameSafe(this), *GetNameSafe(CurrentTarget)));
	}

	OnAttackBP();
}

void AOMFTriggerTrap::ReloadFinished()
{
	GetWorld()->GetTimerManager().ClearTimer(ReloadedTimer);
	bIsReloaded = true;
}

void AOMFTriggerTrap::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AOMFCharacter* OtherChar = Cast<AOMFCharacter>(OtherActor);

	if (nullptr != OtherChar && UUtilitaries::OMFAttitudeTeamSolver(GetGenericTeamId(), OtherChar->GetGenericTeamId()) == ETeamAttitude::Hostile)
	{
		OverlappedActors.AddUnique(OtherChar);
		//NbTargets++;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("CoucouTrap"));
	}
}

void AOMFTriggerTrap::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AOMFCharacter* OtherChar = Cast<AOMFCharacter>(OtherActor);

	if (nullptr != OtherChar && UUtilitaries::OMFAttitudeTeamSolver(GetGenericTeamId(), OtherChar->GetGenericTeamId()) == ETeamAttitude::Hostile)
	{
		OverlappedActors.Remove(OtherChar);
		//NbTargets--;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Byebye Trap"));
	}
}


