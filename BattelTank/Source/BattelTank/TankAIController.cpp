// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();// �������� ����� ������ 

	if (!PlayerPawn) {return nullptr;}

	return Cast<ATank>(PlayerPawn); //������ � ��� ������ PlayerPawn
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto HitLocation = GetPlayerTank()->GetActorLocation();
	GetControlledTank()->AimAt(HitLocation);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controlled %s does not see the tank"),*(ControlledTank->GetName()));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("	AI_controlled %s targets a tank %s"), *(ControlledTank->GetName()), *(PlayerTank->GetName()));
	}
}
