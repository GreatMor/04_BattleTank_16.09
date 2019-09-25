// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChage = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;//Изменение высоты
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChage;// New Elevation
	auto Elevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);//Limitation of elevation Barrel

	SetRelativeRotation(FRotator(Elevation, 0, 0));

}