// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetPawn()) { return; }
	auto AmingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();	

	if (!ensure(AmingComponent)) { return; }
	FounaAmingComponent(AmingComponent);
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PassesPawn = Cast <ATank>(InPawn);
		if (!ensure(InPawn)) { return; }
		PassesPawn->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPassedTankDeath);
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	auto AmingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(!AmingComponent)) { return; }

	FVector HitLocation; // OutParameter
	auto bGetSighetHitLocation = GetSighetHitLocation(HitLocation);

	if (bGetSighetHitLocation) // All rights reserved.
	{
		 AmingComponent->AimAt(HitLocation);
	}
}

//Get world location of lintrace through crosshair, return true if hit landscape
//(Получить мировое местоположение Линтрейса через перекрестие, вернуть true, если ударил ландшафт)
bool ATankPlayerController::GetSighetHitLocation(FVector& HitLocation) const
{
	//Find the crosshair position
	// (Найти положение прицела)
	int32 ViewportSizeX, ViewportSizeY;//Out parametre
	GetViewportSize(ViewportSizeX, ViewportSizeY);//Получение размера монитора

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection; // OUT param

	if (GetLookDirektion(ScreenLocation, LookDirection))
	{
		return GetLoolVectorHitLocation(LookDirection, HitLocation);
	}
	return false;
}


// Get the direction of the sight
bool ATankPlayerController::GetLookDirektion(FVector2D ScreenLocation, FVector& LookDirection)const
{
	FVector CameraWorldLocation;//Out parametre

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

bool ATankPlayerController::GetLoolVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;// parameter for LineTraceSingleByChannel (struct FHitResult & OutHit,) return HitResult(ìåñòî óäàðà ëó÷à)
	auto StartLocation = PlayerCameraManager->GetCameraLocation();// parameter for LineTraceSingleByChannel (Start)
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);// parameter for LineTraceSingleByChannel (end)

	if (GetWorld()->LineTraceSingleByChannel(  //Trace a ray against the world using a specific channel and return the first blocking hit
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);
	return false;
}

void ATankPlayerController::OnPassedTankDeath()
{
	StartSpectatingOnly();
}

