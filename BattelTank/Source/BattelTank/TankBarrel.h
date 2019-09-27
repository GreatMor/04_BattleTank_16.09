// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))

class BATTELTANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, and +1 is max speed up movement 
	void Elevate(float RelativeSpeed);

private:
	 
	UPROPERTY(EditAnyWhere, category = "Setup")
	float MaxDegreesPerSecond = 20;//

	UPROPERTY(EditAnyWhere, category = "Setup")
	float MaxElevationDegrees= 40;//


	UPROPERTY(EditAnyWhere, category = "Setup")
	float MinElevationDegrees = 40;//
};
