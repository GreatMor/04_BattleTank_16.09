#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

<<<<<<< HEAD
=======

#include "TankAimingComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
>>>>>>> origin/master

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

<<<<<<< HEAD
void UTankAimingComponent::SetBarrelRefernce(UTankBarrel* BarrelToSet)
{
	//if (!BarrelToSet) { return; }
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LounchSpeed)
{
	if (!Barrel) { return; };

	FVector OutLounchVelocity; // OUT param
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	//Calculete the OutLounchVelocity
	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(this, OutLounchVelocity, StartLocation,
		WorldSpaceAim, LounchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace));//ГЏГ°ГҐГ¤Г«Г®Г¦ГЁГІГј Г±ГЄГ®Г°Г®Г±ГІГј Г±Г­Г Г°ГїГ¤Г 

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLounchVelocity.GetSafeNormal();// AimDirection (Г­Г ГЇГ°Г ГўГ«ГҐГ­ГЁГҐ ГЇГ°ГЁГ¶ГҐГ«ГЁГўГ Г­ГЁГї) 		
		MoveBarrelTowards(AimDirection);
	}
=======
void UTankAimingComponent::SetBarrelRefernce(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector WorldSpaceAim, float LounchSpeed)
{
	if (!Barrel) { return; };
	
	FVector OutLounchVelocity; // OUT param
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	//Calculete the OutLounchVelocity	

	bool bHaveAimSolution = (UGameplayStatics::SuggestProjectileVelocity(this, OutLounchVelocity, StartLocation,
		WorldSpaceAim, LounchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace));//Предложить скорость снаряда

	if (bHaveAimSolution)
		{
		auto AimDirection = OutLounchVelocity.GetSafeNormal();// AimDirection (направление прицеливания) 		
		MoveBarrelTowards(AimDirection);
		}		
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();// Направления пушки
	auto AimAsRotator = AimDirection.Rotation();

	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator %s:"), *AimAsRotator.ToString());
	//Получить разницу между положением пушки 
	//SetRotationTurret
	//SetRotatioBarrel
>>>>>>> origin/master
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
 	auto BarrelRotator = Barrel->GetForwardVector().Rotation();// ГЌГ ГЇГ°Г ГўГ«ГҐГ­ГЁГї ГЇГіГёГЄГЁ
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator; //

	Barrel->Elevate(5);
	//SetRotationTurret
	//SetRotatioBarrel
}