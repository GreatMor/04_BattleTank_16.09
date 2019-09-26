
#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::SetBarrelRefernce(UTankBarrel* BarrelToSet)
{
	if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}
void UTankAimingComponent::SetTurretRefernce(UTankTurret* TurretToSet)
{
	if (!TurretToSet) { return; }
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LounchSpeed)
{
	if (!Barrel) { return; };

	FVector OutLounchVelocity; // OUT param
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculete the OutLounchVelocity
	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(this, OutLounchVelocity, StartLocation,
		WorldSpaceAim, LounchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace));// Suggest projectile speed

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLounchVelocity.GetSafeNormal();// AimDirection 
		MoveBarrelTowards(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f aim solution found "), Time);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f no aim solve fount "), Time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
 	auto BarrelRotator = Barrel->GetForwardVector().Rotation();//// Barrel directions
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator; //

	Barrel->Elevate(DeltaRotator.Pitch);

	if (FMath::Abs(DeltaRotator.Yaw) > 180.f)
	 { DeltaRotator.Yaw *= (-1.f); }

	Turret->Rotate(DeltaRotator.Yaw);
}
