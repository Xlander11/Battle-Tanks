// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "../Public/TankAIController.h"




void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("No controlled Tanks"));
	}else{
		UE_LOG(LogTemp, Warning, TEXT("AI %s successfully spawned"), *ControlledTank->GetName());
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("No Player controlled Tanks"));
	}else {
		UE_LOG(LogTemp, Warning, TEXT("Player controlled Tanks Found %s"), *PlayerTank->GetName());
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto AITank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (PlayerTank) {
		if (AITank) {
			AITank->AimAt(GetPlayerTank()->GetActorLocation());

			// Fire if ready
		}
	}
}

ATank *ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}