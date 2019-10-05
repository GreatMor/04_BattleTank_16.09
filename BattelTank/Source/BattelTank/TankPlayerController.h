

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//Forward Diclaration

class UTankAimingComponent;

UCLASS()
class BATTELTANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
protected:

		
	UFUNCTION(BlueprintImplementableEvent, category = "Setup")
	void FounaAmingComponent(UTankAimingComponent* AimCopmRef);

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	
	void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnyWhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnyWhere)
	float CrossHairYLocation = 0.33333f;

	UPROPERTY(EditAnyWhere)
	float LineTraceRange = 1000000;

	bool GetLookDirektion(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLoolVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	// Method moves the barrel of the tank so
	// so that you can shoot where the sight crosses the world
	void AimTowardsCrosshair();

	// Return an Out paramete,  true if hit landscape
	bool GetSighetHitLocation(FVector& HitLocation) const;

	UFUNCTION()
	void OnPassedTankDeath();

	virtual void SetPawn(APawn* InPawn)override;
};