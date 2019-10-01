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

	UTankTrack();
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/*void ApplySidewaysForce();*/

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetTrottele(float Throttle);

	//Max force per track, in Newtons
	UPROPERTY(EditAnyWhere, Category = Input)
	float TrackMaxDrivingForce = 40000000;// Assume 40 tonne tank, and 1g accelleration
};
