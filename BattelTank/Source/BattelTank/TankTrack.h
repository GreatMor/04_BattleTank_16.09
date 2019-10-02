// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTELTANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:

	
	void ApplySidewaysForce();

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetTrottele(float Throttle);

	void DriveTrack();

	//Max force per track, in Newtons
	UPROPERTY(EditAnyWhere, Category = Input)
	float TrackMaxDrivingForce = 65000000;// Assume 40 tonne tank, and 1g accelleration

private:

	UTankTrack();

	virtual void BeginPlay()override;
	
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	/** Delegate for notification of start of overlap with a specific component */

	float CurretThrottle = 0;
};
