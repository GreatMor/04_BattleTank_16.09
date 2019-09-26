// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);

	auto RoateChage = MaxDegreesPerSecond * RelativeSpeed * GetWorld()->DeltaTimeSeconds;// changing the position of the turret
	auto RawNewRotate = RelativeRotation.Yaw + RoateChage;// New Rotate

	SetRelativeRotation(FRotator(0, RawNewRotate, 0));

}
