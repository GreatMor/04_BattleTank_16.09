
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
	bWantsBeginPlay = true;

	PrimaryComponentTick.bCanEverTick = true;
}
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	//auto AmingComponent = GetOwner()->FindComponentByClass<UTankAimingComponent>();
	//if (!ensure(AmingComponent)) { return; }

	//FounaAmingComponent(AmingComponent);
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
		auto AimDirection = OutLounchVelocity.GetSafeNormal();// AimDirection 
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
