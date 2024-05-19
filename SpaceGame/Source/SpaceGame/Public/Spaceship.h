// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Laser.h"
#include "Shield.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include"GameFramework/SpringArmComponent.h"
#include "Spaceship.generated.h"

UCLASS()
class SPACEGAME_API ASpaceship : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceship();
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SpaceshipBase;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SpaceshipTurret;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SpaceshipBarrel;

	UPROPERTY(EditAnywhere)
		UCameraComponent*Camera;
	UPROPERTY(EditAnywhere)
		USpringArmComponent* SpringArm;
	UPROPERTY(EditAnywhere)
		float MovementSpeed;
	UPROPERTY(EditAnywhere)
     TSubclassOf<ALaser> LaserClass;
    void SpawnLaser();
	UPROPERTY(EditAnywhere)
     TSubclassOf<AShield> ShieldClass;
    void SpawnShield();

	UPROPERTY(EditAnywhere)
	int PreciousMetalCounter;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
