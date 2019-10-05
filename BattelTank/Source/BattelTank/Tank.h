#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


UCLASS()
class BATTELTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	virtual float TakeDamage
	(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser
	)override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category="Setup")
	int32 StartingHelth = 100;

	int32 CurrenHelth = StartingHelth;
};