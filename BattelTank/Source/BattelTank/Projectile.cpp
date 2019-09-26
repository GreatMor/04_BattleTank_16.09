// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Engine/World.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create a default Movement component for the tank
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movement Component"));
	ProjectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float SpeedProjectile)
{
	auto Time = GetWorld()->DeltaTimeSeconds;
	UE_LOG(LogTemp, Warning, TEXT("%f fire projectile %f"), Time, SpeedProjectile);

	ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * SpeedProjectile);

	ProjectileMovement->Activate();//Active projectile movement after the projectile flies
}