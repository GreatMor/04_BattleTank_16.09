// Fill out your copyright notice in the Description page of Project Settings.

/**
*TankTrack is used to set maximum driving force, and to apply forces to the tank.
*/
#include "TankTrack.h"

void UTankTrack::SetTrottele(float Throttle)
{
	//Set a trottle between -1 and +1

	auto ForceApplide = GetForwardVector() * Throttle * TrackMaxDrivingForce;/*GetForwardVector() Track Direction(Unit Vector)*/ 
	auto ForceLocation = GetComponentLocation();//  Track loation 
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());//We pass to the primitive component for application-> AddForceAtLocation(ForceApplide, ForceLocation);

	TankRoot->AddForceAtLocation(ForceApplide, ForceLocation);
	
}
