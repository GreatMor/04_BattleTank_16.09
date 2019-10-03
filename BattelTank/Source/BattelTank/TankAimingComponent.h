#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UObject/Class.h"
#include "TankAimingComponent.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;
class AProjectile;

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked,
	NoShells
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTELTANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable)
	void Fire();

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initilaize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);// Sets the link to the tank barrel and turret

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	float GetCurrentSell()const;

	EFiringState GetFiringState() const;
	
protected:

	UPROPERTY(BlueprintReadOnly, Category = "Setup")
	EFiringState FiringState= EFiringState::Reloading;

	UFUNCTION(BlueprintImplementableEvent, category = "Setup")
	void FounaAmingComponent(UTankAimingComponent* AimCopmRef);

	UTankBarrel* Barrel = nullptr;

private:

	// Sets default values for this component's properties
	UTankAimingComponent();

	virtual void BeginPlay()override;

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)override;	

	UTankTurret * Turret = nullptr;

	void MoveBarrelTowards(FVector AimDir);	// Move barrel to direction

	UPROPERTY(EditAnyWhere, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditAnyWhere, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnyWhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;

	bool IsBarrelMoving();

	FVector AimDirection;

	UPROPERTY(EditAnyWhere)
	float Shell = 3;
};
	

