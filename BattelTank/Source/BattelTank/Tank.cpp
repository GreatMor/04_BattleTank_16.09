
#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create a default component for the tank
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}


void ATank::Fire()
{
	if (!ensure(BarrelRef)) {return;}

	bool isReloade = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if(isReloade)
	{
		//Spawn a projectile at socket location on the barrle
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			BarrelRef->GetSocketLocation(FName("Projectile")),
			BarrelRef->GetSocketRotation(FName(" Projectile "))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}	
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}