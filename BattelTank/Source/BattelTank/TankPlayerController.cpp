// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());//������� ���� ����� ����� ������� �� �������
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
	if (!GetControlledTank()) {return;}

	FVector HitLocation;// Out parameter ����� ����� 

	if (GetSighetHitLocation(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLocation %s"), *(HitLocation.ToString()));
	}
	
}

//Get world location of lintrace through crosshair, return true if hit landscape
//(�������� ������� �������������� ��������� ����� �����������, ������� true, ���� ������ ��������)
bool ATankPlayerController::GetSighetHitLocation(FVector& HitLocation) const
{
	
	//Find the crosshair position
	// (����� ��������� �������)
	int32 ViewportSizeX, ViewportSizeY;//Out parametre

	GetViewportSize(ViewportSizeX, ViewportSizeY);//��������� ������� ��������

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector LookDirection; // OUT param

	if (GetLookDirektion(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look direction %s"), *(LookDirection.ToString()));
	}
	
	return true;
}

// �������� ����������� �������
bool ATankPlayerController::GetLookDirektion(FVector2D ScreenLocation, FVector& LookDirection)const
{
	FVector CameraWorldLocation;//Out parametre
	FVector WorldDirection;//Out parametre

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		WorldDirection
		);	
}


