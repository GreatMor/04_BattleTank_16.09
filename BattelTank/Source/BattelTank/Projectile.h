// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BATTELTANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AProjectile();

	void LaunchProjectile(float SpeedProjectile);

private:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void OnTimerDestroy();

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* CollisionMash = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UParticleSystemComponent* LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UParticleSystemComponent* ImpactBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	URadialForceComponent* ExplosionForce = nullptr;

	UPROPERTY(EditAnyWhere,  Category = "Setup")
	float DestroyDelay = 5;

	UProjectileMovementComponent* ProjectileMovement = nullptr; 
	 
};
