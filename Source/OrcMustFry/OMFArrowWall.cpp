// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFArrowWall.h"
#include "OMFProjectile.h"

//Has manual timer, you can put a TimerHandler if your really want to. I Don't 8P
void AOMFArrowWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (timer >= cooldown)
	{
		timer = 0;
		if (isShooting)
		{
			//Yes, I'm shooting like this. Yes it's disgusting. But it works. You can refactor to find all socket names
			//then juste loop on those instead of this horrid bit of code
			if (nullptr != GetWorld())
			{
				AOMFProjectile* CurrentProjectile = nullptr;

				CurrentProjectile = GetWorld()->SpawnActor<AOMFProjectile>(ProjectileClass);

				if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->MeshComponent)
				{
					CurrentProjectile->InitProjectile(MeshComponent->GetSocketLocation(TEXT("ProjectileSocket")), MeshComponent->GetSocketRotation(TEXT("ProjectileSocket")).Vector());
				}

				CurrentProjectile = GetWorld()->SpawnActor<AOMFProjectile>(ProjectileClass);

				if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->MeshComponent)
				{
					CurrentProjectile->InitProjectile(MeshComponent->GetSocketLocation(TEXT("ProjectileSocket1")), MeshComponent->GetSocketRotation(TEXT("ProjectileSocket1")).Vector());
				}

				CurrentProjectile = GetWorld()->SpawnActor<AOMFProjectile>(ProjectileClass);

				if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->MeshComponent)
				{
					CurrentProjectile->InitProjectile(MeshComponent->GetSocketLocation(TEXT("ProjectileSocket2")), MeshComponent->GetSocketRotation(TEXT("ProjectileSocket2")).Vector());
				}

				CurrentProjectile = GetWorld()->SpawnActor<AOMFProjectile>(ProjectileClass);

				if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->MeshComponent)
				{
					CurrentProjectile->InitProjectile(MeshComponent->GetSocketLocation(TEXT("ProjectileSocket3")), MeshComponent->GetSocketRotation(TEXT("ProjectileSocket3")).Vector());
				}

				CurrentProjectile = GetWorld()->SpawnActor<AOMFProjectile>(ProjectileClass);

				if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->MeshComponent)
				{
					CurrentProjectile->InitProjectile(MeshComponent->GetSocketLocation(TEXT("ProjectileSocket4")), MeshComponent->GetSocketRotation(TEXT("ProjectileSocket4")).Vector());
				}
			}
			nbProjectileShot += 5;
			if (nbProjectileShot >= nbProjectileToShoot)
			{
				isShooting = false;
			}
		}
	}
	timer += DeltaTime;
}

void AOMFArrowWall::OnValidBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	isShooting = true;
	nbProjectileShot = 0;
	UE_LOG(LogTemp, Log, TEXT("I HAZ OVERLAPPED ! I IZ SHOOTING ! !"));	
}

void AOMFArrowWall::OnValidEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Log, TEXT("I HAZ FINISHED OVERLAPPING !!! I IZ STOP SHOOTING WEHN DONE !"));
}
