// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFProjectile.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
AOMFProjectile::AOMFProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;		

	//Instantiate root
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void AOMFProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	//Give him the delegate for collision
	if (nullptr != MeshComponent)
	{
		MeshComponent->OnComponentHit.AddUniqueDynamic(this, &AOMFProjectile::OnProjectileHit);
	}

}

// Called every frame
void AOMFProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Initialize projectile giving him location to be, setting to ignore gravity and giving it speed
void AOMFProjectile::InitProjectile(FVector Location,FVector ForwardWeapon)
{
	SetActorLocation(Location);
	MeshComponent->SetEnableGravity(false);
	MeshComponent->SetAllPhysicsLinearVelocity(Speed * ForwardWeapon);
}

//Behavior from the projectile on hit
void AOMFProjectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}
