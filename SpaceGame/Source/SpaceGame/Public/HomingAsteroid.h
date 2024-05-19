// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Asteroid.h"
#include "HomingAsteroid.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAME_API AHomingAsteroid : public AAsteroid
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
     float MovementSpeed = 2000
    ;
    UPROPERTY(EditAnywhere)
     float AttackRadius = 2000
    ;
    AActor* PlayerShip
    ;

 UFUNCTION()
 
 virtual void Tick(float DeltaSeconds) override
 ;
 virtual void BeginPlay() override
 ;
 
};
