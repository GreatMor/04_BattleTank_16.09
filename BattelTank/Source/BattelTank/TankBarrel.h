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
	UFUNCTION(BlueprintCallable)
	void Elevate(float DegrresPerSecond);

private:
	 
	UPROPERTY(EditAnywhere, category = "Setup")
	float MaxDegreesPerSecond = 20;//

	UPROPERTY(EditAnywhere, category = "Setup")
	float MaxElevationDegrees= 40;//
};
