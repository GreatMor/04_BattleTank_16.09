// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 *
 */
UCLASS()
class BATTELTANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:

	void BeginPlay() override;

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank()const; //Will return a pointer to the player’s tank

	virtual void Tick(float DeltaTime) override;

};
