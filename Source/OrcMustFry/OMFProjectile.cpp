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

	MeshBodyComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshBodyComponent"));

	//Instantiate Projectile movement Component
	projectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
	projectileComponent->SetUpdatedComponent(MeshComponent);
	projectileComponent->InitialSpeed = 1000.0f;
	projectileComponent->MaxSpeed = 1000.0f;
	projectileComponent->bRotationFollowsVelocity = true;
	projectileComponent->bShouldBounce = false;
	projectileComponent->Bounciness = 0.0f;

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

void AOMFProjectile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//Do nothing here. Serves to be overloaded in children.
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
	/*MeshComponent->SetEnableGravity(false);
	MeshComponent->SetAllPhysicsLinearVelocity(Speed * ForwardWeapon);*/
	projectileComponent->Velocity = (ForwardWeapon * projectileComponent->InitialSpeed);
}

//Behavior from the projectile on hit (Linked to delegate, useless to overload. Overload OnValidHit() to define collision behavior instead)
void AOMFProjectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	OnValidHit( HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
}

//Actual function where collision behavior will occur
void AOMFProjectile::OnValidHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//Do stuff in daughter classes. This function purely serves to be overloaded. NOT TO EVER IMPLEMENT ANY BEHAVIOR HERE
}
