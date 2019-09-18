// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

UCLASS()
class BATTELTANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTank() const;

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//Метод перемещает ствол танка так,
	//что бы можно было выстрелить туда где прицел пересикается с миром
	void AimTowardsCrosshair();

	// Return an Out paramete,  true if hit landscape
	bool GetSighetHitLocation(FVector& HitLocation) const;
		
};
