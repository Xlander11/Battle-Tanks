// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No controlled Tanks"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("He's AAALIVEEEEEEE %s"), *ControlledTank->GetName());
	}
}


ATank *ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}