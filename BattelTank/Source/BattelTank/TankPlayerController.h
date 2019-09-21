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

private:
	ATank* GetControlledTank() const;

	void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//����� ���������� ����� ����� ���,
	//��� �� ����� ���� ���������� ���� ��� ������ ������������ � �����
	void AimTowardsCrosshair();

	// Return an Out paramete,  true if hit landscape
	bool GetSighetHitLocation(FVector& HitLocation) const;

	bool GetLookDirektion(FVector2D ScreenLocation, FVector& LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

		
};
