// Fill out your copyright notice in the Description page of Project Settings.

/**
*TankTrack is used to set maximum driving force, and to apply forces to the tank.
*/

#include "TankTrack.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"


UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;	
}

void UTankTrack::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);//where to find the method when the event worked
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTrack();
	ApplySidewaysForce();
	CurretThrottle = 0;
}

void UTankTrack::SetTrottele(float Throttle)
{
	CurretThrottle = FMath::Clamp<float>(CurretThrottle + Throttle, -1,+1);
}

void UTankTrack::DriveTrack()
{
	//Set a trottle between -1 and +1
	auto ForceApplide = GetForwardVector() * CurretThrottle * TrackMaxDrivingForce;/*GetForwardVector() Track Direction(Unit Vector)*/
	auto ForceLocation = GetComponentLocation();//  Track loation 
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());//We pass to the primitive component for application-> AddForceAtLocation(ForceApplide, ForceLocation);

	TankRoot->AddForceAtLocation(ForceApplide, ForceLocation);
}

void UTankTrack::ApplySidewaysForce()
{
	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());//–ассчитайте скал€рное произведение двух векторов. бокового вектора и скорости
	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto  CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();//ускорение танка при поворотах

	// –ассчитать и применить вбок (F = ma)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());// Get RootComponent tank 
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tarac
	TankRoot->AddForce(CorrectionForce);
}
