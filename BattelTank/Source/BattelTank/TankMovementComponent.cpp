// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initilaize(UTankTrack* LeftTrackToSet, UTankTrack* RighetTrackToSet)
{	
	LeftTrack = LeftTrackToSet;
	RighetTrack = RighetTrackToSet;
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

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{

	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();//Tank direction ai
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();//Movement direction of the tank ai
	auto MoveAiTank = FVector::DotProduct(TankForward, AiForwardIntention);

	IntendMoveForward(MoveAiTank);
	
	UE_LOG(LogTemp, Warning, TEXT("MoveVelocity ai  %f:"), MoveAiTank);
}
