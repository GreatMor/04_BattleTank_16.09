

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

	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;

	bool GetLookDirektion(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLoolVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	// Method moves the barrel of the tank so
	// so that you can shoot where the sight crosses the world
	void AimTowardsCrosshair();

	// Return an Out paramete,  true if hit landscape
	bool GetSighetHitLocation(FVector& HitLocation) const;


};