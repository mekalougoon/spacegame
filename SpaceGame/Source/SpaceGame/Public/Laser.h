// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Asteroid.h"
#include "GameFramework/Actor.h"
#include "Laser.generated.h"

UCLASS()
class SPACEGAME_API ALaser : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALaser();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* LaserMesh;
	float TimeAlive;
	float MaxTime;
	float MovementSpeed;
	AActor* Parent;
	
	UFUNCTION()
		void OnLaserOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool
bFromSweep, const FHitResult& SweepResult);

	UPROPERTY
	(EditAnywhere)TSubclassOf<AAsteroid> ResourceAsteroidClass
   ;
	void SpawnResource(FTransform SpawnLocation);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
