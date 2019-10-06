#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegat);

UCLASS()
class BATTELTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	virtual float TakeDamage(float DamageAmount,struct FDamageEvent const& DamageEvent,class AController* EventInstigator,AActor* DamageCauser)override;

	//Return current health as a Percentage of starting hialth , between 0 and 1
	UFUNCTION(BlueprintPure, category = "Health")
	float GetHealthPercentage();

	UPROPERTY(BlueprintAssignable, Category = "Test")
	FTankDelegat OnDeath;
	
private:

	virtual void BeginPlay()override;

	// Sets default values for this pawn's properties
	ATank();
		
	UPROPERTY(EditDefaultsOnly, Category="Setup")
	int32 StartingHelth = 100;

	int32 CurrenHelth;
};