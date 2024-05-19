// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Laser.h"
#include "GameFramework/Actor.h"
#include "SpaceStation.generated.h"

UCLASS()
class SPACEGAME_API ASpaceStation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpaceStation();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SpaceStationBase;

	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SpaceStationTurret;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ALaser> LaserClass;
	void SpawnLaser();

	FTimerHandle BulletTimerHandle;

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
