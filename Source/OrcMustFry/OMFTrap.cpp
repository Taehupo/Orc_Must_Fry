// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFTrap.h"


// Sets default values
AOMFTrap::AOMFTrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	ColliderBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ColliderBox"));

	RootComponent = MeshComponent;

	ColliderBox->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AOMFTrap::BeginPlay()
{
	Super::BeginPlay();

	if (nullptr != MeshComponent)
	{
		ColliderBox->OnComponentBeginOverlap.AddDynamic(this, &AOMFTrap::OnTrapBeginOverlap);
		ColliderBox->OnComponentEndOverlap.AddDynamic(this, &AOMFTrap::OnTrapEndOverlap);
	}
	
}

// Called every frame
void AOMFTrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOMFTrap::InitTrap(FVector Location)
{
	
}

void AOMFTrap::OnTrapBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnValidBeginOverlap(OverlappedComp ,OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void AOMFTrap::OnTrapEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	OnValidEndOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
}

void AOMFTrap::OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AOMFTrap::OnValidEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}