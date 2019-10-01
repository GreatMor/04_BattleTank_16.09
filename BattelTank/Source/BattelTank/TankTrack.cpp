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

void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
//Calculate the sllipage speed 
auto SllipageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());

//Wor - out the rewquired acceleration rhis frame to correct
auto CorrectionAcceleration = -SllipageSpeed / DeltaTime * GetRightVector();

// Calculate and apply sideways for (f = m a)
auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
auto CorrectionForce = TankRoot->GetMass() * CorrectionAcceleration / 2; // 2 track

TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetTrottele(float Throttle)
{
	//Set a trottle between -1 and +1

	auto ForceApplide = GetForwardVector() * Throttle * TrackMaxDrivingForce;/*GetForwardVector() Track Direction(Unit Vector)*/ 
	auto ForceLocation = GetComponentLocation();//  Track loation 
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());//We pass to the primitive component for application-> AddForceAtLocation(ForceApplide, ForceLocation);

	TankRoot->AddForceAtLocation(ForceApplide, ForceLocation);

	UE_LOG(LogTemp, Warning, TEXT("%s tr tr tr %s"), *ForceApplide.ToString(), *ForceLocation.ToString())
	
}
//void UTankTrack::ApplySidewaysForce()
//{
//	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());//–ассчитайте скал€рное произведение двух векторов. бокового вектора и скорости
//	auto DeltaTime = GetWorld()->GetDeltaSeconds();
//	auto  CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();//ускорение танка при поворотах
//
//	// –ассчитать и применить вбок (F = ma)
//	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());// Get RootComponent tank 
//	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Two tarac
//	TankRoot->AddForce(CorrectionForce);
//}
