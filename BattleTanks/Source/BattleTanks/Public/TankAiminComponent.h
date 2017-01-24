// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAiminComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAiminComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAiminComponent();

	void SetBarrelReference(UStaticMeshComponent *BarrelToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);
	

private:
	UStaticMeshComponent *Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
