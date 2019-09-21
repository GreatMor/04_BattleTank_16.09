// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Camera/PlayerCameraManager.h"

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
		//UE_LOG(LogTemp, Warning, TEXT("PlayControlled not possesing a Tank"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("PlayControlled possesing  %s"), *(ControlledTank->GetName()));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	FVector HitLocation; // OutParameter	

	if (!GetControlledTank()) { return; }
	if (GetSighetHitLocation(HitLocation)) // Все права защищены.
	{
		UE_LOG(LogTemp, Warning, TEXT(" HitLocation: % s "), *HitLocation.ToString());
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
		GetLoolVectorHitLocation(LookDirection, HitLocation);
	}
	
	return true;
}

// Получить направление прицела
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
	FHitResult HitResult;// parameter for LineTraceSingleByChannel (struct FHitResult & OutHit,) return HitResult(????? ????? ????)
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


