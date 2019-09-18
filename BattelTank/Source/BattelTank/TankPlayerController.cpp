// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());//Передаём типу АТанк пешку которой он владеет
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayControlled not possesing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayControlled possesing  %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {return;}

	FVector HitLocation;// Out parameter Место удара 

	if (GetSighetHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *(HitLocation.ToString()));
	}
	
}

//Get world location of lintrace through crosshair, return true if hit landscape
//(Получить мировое местоположение Линтрейса через перекрестие, вернуть true, если ударил ландшафт)
bool ATankPlayerController::GetSighetHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return true;
}
