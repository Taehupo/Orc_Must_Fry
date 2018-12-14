// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFProjectile.h"

#include "OMFProjectileComponent.h"
#include "OMFTrap.h"
#include "OMFWeapon.h"

#include "Components/StaticMeshComponent.h"
#include "Particles/Emitter.h"

// Sets default values
AOMFProjectile::AOMFProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;		

	//SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	RootComponent = MeshComponent;

	ProjectileComponent = CreateDefaultSubobject<UOMFProjectileComponent>(TEXT("ProjComponent"));

	/*if(nullptr != MeshComponent && nullptr != RootComponent)
		MeshComponent->SetupAttachment(RootComponent);*/

	OMFLifeSpan = 5.f;

	if (nullptr != ProjectileComponent && nullptr != RootComponent)
		ProjectileComponent->SetUpdatedComponent(RootComponent);
}

// Called when the game starts or when spawned
void AOMFProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	if (nullptr != MeshComponent)
	{
		//MeshComponent->OnComponentHit.AddUniqueDynamic(this, &AOMFProjectile::OnProjectileHit);
		MeshComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &AOMFProjectile::OnProjectileHit);
	}

	if(OMFLifeSpan != 0.f)
		GetWorld()->GetTimerManager().SetTimer(ProjectileTimerHandle, this, &AOMFProjectile::OnLifeEnded, OMFLifeSpan, false);

}

void AOMFProjectile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

}

// Called every frame
void AOMFProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOMFProjectile::InitProjectile(FVector Location,FVector ForwardWeapon)
{
	//SetActorLocation(Location);
	//SetActorLocationAndRotation(Location,FRotationMatrix::MakeFromX(ForwardWeapon).ToQuat());
	if (nullptr != ProjectileComponent)
		ProjectileComponent->Velocity = ForwardWeapon * ProjectileComponent->InitialSpeed;
}

void AOMFProjectile::OnProjectileHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if(IsValidActorForCollision(OtherActor))
		OnLifeEnded();
		
		//OMFProjectileHit(OtherActor, OtherComp, NormalImpulse, Hit);
}

bool AOMFProjectile::IsValidActorForCollision(AActor* _OtherActor)
{
	if (nullptr != _OtherActor && !_OtherActor->IsA<AOMFProjectile>() && !_OtherActor->IsA<AOMFTrap>() && !_OtherActor->IsA<AOMFWeapon>())
		return true;

	return false;
}

//void AOMFProjectile::OMFProjectileHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
//{
//	//GetWorld()->GetTimerManager().ClearTimer(ProjectileTimerHandle);
//	OnLifeEnded();
//}

void AOMFProjectile::OnLifeEnded()
{
	if (nullptr != ProjectileComponent)
	{
		ProjectileComponent->StopMovementImmediately();
		ProjectileComponent->SetUpdatedComponent(nullptr);
	}

	SetLifeSpan(3.f);
	GetWorld()->GetTimerManager().ClearTimer(ProjectileTimerHandle);
	EndLifeDel.ExecuteIfBound();
	OnLifeEndedBP();
}