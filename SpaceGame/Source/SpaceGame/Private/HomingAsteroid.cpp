// Fill out your copyright notice in the Description page of Project Settings.


#include "HomingAsteroid.h"



void AHomingAsteroid::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(FVector::Dist(PlayerShip->GetActorLocation(), GetActorLocation()) < AttackRadius)
{
		
	FVector CurrentLocation = GetActorLocation();
	FVector PlayerLocation = PlayerShip->GetActorLocation();
	FVector MovementDirection = PlayerLocation - CurrentLocation;
		//UE_LOG(LogTemp, Warning, TEXT("Homing Asteroid: %s has a direction of: %s"), *GetName(), *MovementDirection.ToString());
	MovementDirection.Normalize();
		//UE_LOG(LogTemp, Warning, TEXT("Homing Asteroid: %s has a normalised direction of: %s"), *GetName(), *MovementDirection.ToString());
	FVector NewLocation = CurrentLocation + MovementDirection * MovementSpeed * DeltaSeconds;
	SetActorLocation(NewLocation); }
}

void AHomingAsteroid::BeginPlay()
{
	Super::BeginPlay();
	PlayerShip = GetWorld()->GetFirstPlayerController()->GetPawn();

}
