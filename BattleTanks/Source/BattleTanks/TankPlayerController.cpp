// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		//UE_LOG(LogTemp, Warning, TEXT("No controlled Tanks"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("He's AAALIVEEEEEEE %s"), *ControlledTank->GetName());
	}
}


void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AimTowardCrosshair();
}


ATank *ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
	}

	// if it hits landscape then move barrel to location
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const {
	HitLocation = FVector(1.f);

	// find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation : %s"), *ScreenLocation.ToString());
	// de-project the screen position of the crosshair to a world direction
	// line trace along that look direction, and see what's get hitten
	return true;
}
