// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // generated.h should always be last to be include

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()


public:
	ATank *GetControlledTank() const;
	
	void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	/*Start the tank moving the barrel towards so that a shot
	would hit where the crosshair intersects the world*/
	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector &HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;
};
