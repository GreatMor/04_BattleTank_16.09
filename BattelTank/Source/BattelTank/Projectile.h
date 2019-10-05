// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BATTELTANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(float SpeedProjectile);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* CollisionMash = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UProjectileMovementComponent* ProjectileMovement = nullptr; 
};
