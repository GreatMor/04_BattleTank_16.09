
#include "Tank.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}
float ATank::TakeDamage(float DamageAmount,
	struct FDamageEvent const& DamageEvent,
	class AController* EventInstigator,
	AActor* DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);

	int32 DamageToAplay = FMath::Clamp<float>(DamagePoints, 0, CurrenHelth);

	CurrenHelth -= DamageToAplay;
	if (CurrenHelth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank died"));
	}
	
	return DamageToAplay;
}




