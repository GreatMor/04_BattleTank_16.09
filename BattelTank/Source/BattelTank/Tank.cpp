
#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//Create a default component for the tank
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelRefernce(BarrelToSet);
	BarrelRef = BarrelToSet;
}

void ATank::SetTurretlReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretRefernce(TurretToSet);
}

void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire"));
	if (!BarrelRef) { return; }
	else
	{
		//Spawn a projectile at socket location on the barrle
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			BarrelRef->GetSocketLocation(FName("Projectile")),
			BarrelRef->GetSocketRotation(FName(" Projectile "))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
	}
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}