
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankTurret.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;

	PrimaryComponentTick.bCanEverTick = true;
}
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	LastFireTime = FPlatformTime::Seconds();
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }

	auto BarrelForward = Barrel->GetForwardVector();
	return !BarrelForward.Equals(AimDirection, 0.01);
}

void UTankAimingComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	if ((FPlatformTime::Seconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringState = EFiringState::Reloading;
	}
	else if (IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
	{
		FiringState = EFiringState::Locked;
	}

}


void UTankAimingComponent::Initilaize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) { return; }
	FVector OutLounchVelocity; // OUT param
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculete the OutLounchVelocity
	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(this, OutLounchVelocity, StartLocation,
		HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace));// Suggest projectile speed

	if (bHaveAimSolution)
	{
		AimDirection = OutLounchVelocity.GetSafeNormal();// AimDirection 
		MoveBarrelTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

	if (!ensure(Barrel)|| !ensure(Turret)) { return; };

 	auto BarrelRotator = Barrel->GetForwardVector().Rotation();//// Barrel directions
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator; //

	Barrel->Elevate(DeltaRotator.Pitch);

	if (FMath::Abs(DeltaRotator.Yaw) > 180.f)
	 { DeltaRotator.Yaw *= (-1.f); }

	Turret->Rotate(DeltaRotator.Yaw);
}

void UTankAimingComponent::Fire()
{	
	if ((FiringState == EFiringState::Locked) || (FiringState == EFiringState::Aiming))
	{
		if (!ensure(Barrel && ProjectileBlueprint)) { return; }

		//Spawn a projectile at socket location on the barrle
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName(" Projectile "))
			);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}	
}

