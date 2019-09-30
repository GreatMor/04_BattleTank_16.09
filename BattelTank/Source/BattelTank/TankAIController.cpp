// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());//Location of the player�s tank  (����� ��������� ����� ������) 
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (ensure(PlayerTank))
	{
		//Move towards the player

		MoveToActor(PlayerTank, AcceptanceRadius);
		//Aim towards the player (��������� �� ���� ������ )

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		ControlledTank->Fire();
	}
}	

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


