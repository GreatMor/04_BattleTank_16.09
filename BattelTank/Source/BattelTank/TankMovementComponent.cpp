// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initilaize(UTankTrack* LeftTrackToSet, UTankTrack* RighetTrackToSet)
{	
	LeftTrack = LeftTrackToSet;
	RighetTrack = RighetTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankName = GetOwner()->GetName();
	auto MoveVelocityString = MoveVelocity.ToString();

	UE_LOG(LogTemp, Warning, TEXT("%s MoveVelocity %s:"), *TankName, *MoveVelocityString);
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{	
	if (!LeftTrack || !RighetTrack) { return; };
	LeftTrack->SetTrottele(Throw);
	RighetTrack->SetTrottele(Throw);
}

void UTankMovementComponent::IntendTurnRighet(float Throw)
{
	if (!LeftTrack || !RighetTrack) { return; };
	LeftTrack->SetTrottele(Throw);
	RighetTrack->SetTrottele(-Throw);
}
