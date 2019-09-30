// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();//Location of the player’s tank  (Место нахождене танка игрока) 
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return;}
	
	auto TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim towards the player (Нацелится на танк игрока )
	TankAimingComponent->AimAt(PlayerTank->GetActorLocation());

	//shoot the player
	//TankAimingComponent->Fire();	
}	

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


