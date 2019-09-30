#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Diclaration
class UTankBarrel;
class UTankAimingComponent;
class AProjectile;

UCLASS()
class BATTELTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void BeginPlay()override;
	
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	// local barrel reference for spawn Projectile
	UTankBarrel* BarrelRef = nullptr;

protected:
	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditAnyWhere, Category = "Firing")
	float LaunchSpeed = 4000;

	UPROPERTY(EditAnyWhere, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditAnyWhere, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	double LastFireTime = 0;	
};