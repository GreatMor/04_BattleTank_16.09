#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;// Forward declaration

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTELTANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LounchSpeed);

	void SetBarrelRefernce(UTankBarrel* BarrelToSet);//Óñòàíàâëèâàåò ññûëêó íà ñòâîë òàíêà

private:
<<<<<<< HEAD

	UPROPERTY(EditAnywhere)
	UTankBarrel* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDir);//Ïåðåìåñòèòü ñòâîë â íàïðàâëåíèå
};
=======
	UStaticMeshComponent* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDir);//����������� ����� � �����������
};
>>>>>>> origin/master
