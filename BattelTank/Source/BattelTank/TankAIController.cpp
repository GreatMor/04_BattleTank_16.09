// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PassesPawn = Cast <ATank>(InPawn);
		if (!ensure(InPawn)) { return; }
		PassesPawn->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPassedTankDeath);
	}
}


void ATankAIController::OnPassedTankDeath()
{
	if (!ensure(GetPawn())) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();//Location of the player�s tank  (����� ��������� ����� ������) 
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim towards the player (��������� �� ���� ������ )
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	//shoot the player
	if (AimingComponent->GetFiringState() == EFiringState::Locked)// ai tank does not shoot until it captures the target
	{
		AimingComponent->Fire();
	}
}

