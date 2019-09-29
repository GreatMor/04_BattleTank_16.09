#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTELTANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initilaize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);// Sets the link to the tank barrel and turret

private:

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDir);	// Move barrel to direction
};
	

