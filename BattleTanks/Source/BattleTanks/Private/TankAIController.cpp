// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"




void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No controlled Tanks"));
	}else{
		UE_LOG(LogTemp, Warning, TEXT("AI %s successfully spawned"), *ControlledTank->GetName());
	}
}

ATank *ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}