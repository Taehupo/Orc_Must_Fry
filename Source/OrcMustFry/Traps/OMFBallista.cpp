// Fill out your copyright notice in the Description page of Project Settings.

#include "OMFBallista.h"

#include "OMFProjectileComponent.h"
#include "Projectiles/OMFProjectile.h"
#include "OMFCharacter.h"

#include "Components/SphereComponent.h"

void AOMFBallista::SetupProjectile(class AOMFProjectile* CurrentProjectile, FTransform _WorldTransform)
{
	Super::SetupProjectile(CurrentProjectile, _WorldTransform);

	if (nullptr != CurrentProjectile && nullptr != CurrentProjectile->ProjectileComponent && OverlappedActors.Num() > CurrentIndexTarget && nullptr != OverlappedActors[CurrentIndexTarget])
	{
		FVector DirectionToTarget = OverlappedActors[CurrentIndexTarget]->GetActorLocation() - _WorldTransform.GetLocation();
		DirectionToTarget.Normalize();
		CurrentProjectile->ProjectileComponent->Velocity = DirectionToTarget * CurrentProjectile->ProjectileComponent->InitialSpeed;
		CurrentProjectile->ProjectileComponent->bIsHomingProjectile = true;
		CurrentProjectile->ProjectileComponent->bForceHoming = true;
		CurrentProjectile->ProjectileComponent->HomingTargetComponent = OverlappedActors[CurrentIndexTarget]->GetCapsuleComponent();
	}
}

//void AOMFBallista::OnTriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
//{
//	Super::OnTriggerBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
//	AOMFCharacter* OtherChar = Cast<AOMFCharacter>(OtherActor);
//
//	if (nullptr != OtherChar)
//	{
//		Target = OtherChar;
//		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("CoucouTrap"));
//	}
//}

//void AOMFBallista::OnTriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	Super::OnTriggerEndOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
//
//	AOMFCharacter* OtherChar = Cast<AOMFCharacter>(OtherActor);
//
//	if (nullptr != OtherChar && Target == OtherChar)
//	{
//		TArray<AActor*> OverlapedActor;
//		AOETrigger->GetOverlappingActors(OverlapedActor, AOMFCharacter::StaticClass());
//		
//		Target = nullptr;
//
//		if (OverlapedActor.Num() > 0)
//		{
//			Target = Cast<AOMFCharacter>(OverlapedActor[0]);
//		}
//		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Byebye Trap"));
//	}
//}

void AOMFBallista::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentIndexTarget > 0 && OverlappedActors.Num() > CurrentIndexTarget - 1  && nullptr != OverlappedActors[CurrentIndexTarget - 1])
	{
		FVector Direction = OverlappedActors[CurrentIndexTarget - 1]->GetActorLocation() - GetActorLocation();
		Direction.Normalize();
		Direction.Z = 0.f;
		SetActorRotation(FRotationMatrix::MakeFromX(Direction).Rotator());
	}
}