// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "SpaceStation.h"
#include "AsteroidSpawner.generated.h"


UCLASS()
class SPACEGAME_API AAsteroidSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroidSpawner();
	UPROPERTY
    (EditAnywhere)
     TSubclassOf
		<AAsteroid> AsteroidClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ASpaceStation>SpaceStationClass;

	
	UPROPERTY
	(EditAnywhere)
		int AsteroidsToSpawn;
	UPROPERTY
	(EditAnywhere)
		int MaxTotalAsteroids;
	UPROPERTY
	(EditAnywhere)
		float SpawnRadius;
	UPROPERTY
	(EditAnywhere)
		float SpawnProximity;
	UPROPERTY
	(EditAnywhere)
		float CheckTime;

	FTimerHandle SpawnTimerHandle;
		ASpaceship* PlayerShip;
    TArray
		<AActor*> Asteroids;

	UPROPERTY
	(EditAnywhere)TSubclassOf<AAsteroid> HomingAsteroidClass
   ;
	UPROPERTY(EditAnywhere)
	int HomingSpawnChance =3
   ;
	UPROPERTY(EditAnywhere)
	int StationSpawnChance =1
   ;
	FTimerHandle BulletTimerHandle;

	UFUNCTION()
     void OnTimedSpawn();




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
