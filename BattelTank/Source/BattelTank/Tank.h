#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Diclaration
class UTankBarrel;
class AProjectile;

UCLASS()
class BATTELTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:


	// local barrel reference for spawn Projectile
	UTankBarrel* BarrelRef = nullptr;

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