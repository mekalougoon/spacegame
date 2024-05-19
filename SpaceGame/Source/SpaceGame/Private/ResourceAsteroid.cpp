// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceAsteroid.h"


void AResourceAsteroid::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(FVector::Dist(PlayerShip->GetActorLocation(), GetActorLocation()) < AttackRadius)
	{
		
		FVector CurrentLocation = GetActorLocation();
		FVector PlayerLocation = PlayerShip->GetActorLocation();
		FVector MovementDirection = PlayerLocation - CurrentLocation;
		MovementDirection.Normalize();
		FVector NewLocation = CurrentLocation + MovementDirection * MovementSpeed * DeltaSeconds;
		SetActorLocation(NewLocation); }
}

void AResourceAsteroid::BeginPlay()
{
	Super::BeginPlay();
	PlayerShip = GetWorld()->GetFirstPlayerController()->GetPawn();

}