// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

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

	if (UGameplayStatics::SuggestProjectileVelocity(this, OutLounchVelocity, StartLocation,
		WorldSpaceAim, LounchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))//Предложить скорость снаряда

	{
		auto AimDirectio = OutLounchVelocity.GetSafeNormal();// AimDirection (направление прицеливания) 
		UE_LOG(LogTemp, Warning, TEXT("AimDirection %s:"), *AimDirectio.ToString());
	}
}
