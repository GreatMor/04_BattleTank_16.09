#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/Class.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	test
};

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
protected:

	UPROPERTY(BlueprintReadOnly, Category = "Setup")
	EFiringState FiringState= EFiringState::Locked;

private:

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDir);	// Move barrel to direction
};
	

