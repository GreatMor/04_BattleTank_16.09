#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Diclaration
class UTankBarrel;
class UTankTurret;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTELTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void  SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable)
	void  SetTurretlReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable)
	void Fire();

	// local barrel reference for spawn Projectile
	UTankBarrel* BarrelRef = nullptr;

protected:

	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyWhere, Category = Firing)
	float LaunchSpeed = 4000;

	UPROPERTY(EditAnyWhere, Category = Firing)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnyWhere, Category = Firing)
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;	
};