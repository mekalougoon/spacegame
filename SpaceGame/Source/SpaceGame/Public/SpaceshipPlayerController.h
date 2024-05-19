// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/InputActionDelegateBinding.h"
#include "InputAction.h"
#include "Spaceship.h"
#include "Laser.h"
#include "Shield.h"
#include "GameFramework/PlayerController.h"
#include "SpaceshipPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAME_API ASpaceshipPlayerController : public APlayerController
{
    GENERATED_BODY()
public:
    void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);
    virtual void OnPossess(APawn* InPawn) override;
    virtual void Tick(float DeltaSeconds) override;


    void MoveRightStart();
    void MoveRightEnd();
    void MoveLeftStart();
    void MoveLeftEnd();
    /*void MoveForwardStart();
    void MoveForwardEnd();
    void MoveBackwardStart();
    void MoveBackwardEnd();*/
    void MoveUpStart();
    void MoveUpEnd();
    void MoveDownStart();
    void MoveDownEnd();
	/*void RotateLeftStart();
	void RotateLeftEnd();
	void RotateRightStart();
	void RotateRightEnd();*/
	void ThrusterOn();
	void ThrusterOff();

	FTimerHandle ShieldTimerHandle;

	float CoolDownRemaining;
	
	UFUNCTION()
	void ShieldCooldown();
    
   // FVector MovementInput;
    ASpaceship* PossessedShip;
	FVector2D RotationInput;
	FRotator TargetRotation;
    bool Thruster;


    UPROPERTY(EditAnywhere)
		UInputMappingContext* SpaceshipControls;
    UPROPERTY(EditAnywhere)
		UInputAction* RightAction;
    UPROPERTY(EditAnywhere)
		UInputAction* LeftAction;
    /*UPROPERTY(EditAnywhere)
		UInputAction* ForwardAction;
    UPROPERTY(EditAnywhere)
		UInputAction* BackwardAction;*/
	UPROPERTY(EditAnywhere)
		UInputAction* UpAction;
    UPROPERTY(EditAnywhere)
		UInputAction* DownAction;
	/*UPROPERTY(EditAnywhere)
		UInputAction* RotateLeftAction;
	UPROPERTY(EditAnywhere)
		UInputAction* RotateRightAction;*/
	UPROPERTY(EditAnywhere)
		UInputAction* ThrusterAction;
	UPROPERTY(EditAnywhere)
		UInputAction* LaserAction;
	void FireLaser();

	UPROPERTY(EditAnywhere)
		UInputAction* ShieldAction;
	void FireShield();
};