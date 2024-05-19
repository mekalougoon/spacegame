// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipPlayerController.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "Spaceship.h"





void ASpaceshipPlayerController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    PossessedShip = Cast<ASpaceship>(InPawn);
    if(PossessedShip)
    {
        SetupPlayerInputComponent(InputComponent);
    }
}


void ASpaceshipPlayerController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if(PossessedShip) {
    if(Thruster)
    {
        FVector CurrentLocation = PossessedShip->GetActorLocation();
        FVector NewLocation = CurrentLocation + PossessedShip->GetActorForwardVector()*PossessedShip->MovementSpeed * DeltaSeconds;
        PossessedShip->SetActorLocation(NewLocation);
    }

        if(!RotationInput.IsZero())
        {
            TargetRotation.Pitch += RotationInput.Y;
            TargetRotation.Yaw += RotationInput.X;
            if(TargetRotation.Pitch > 150)
            {
                TargetRotation.Pitch = 150;
                
                UE_LOG(LogTemp, Warning, TEXT("You're going to make me dizzy."));
            }
            else if(TargetRotation.Pitch < -150)
            {
                TargetRotation.Pitch = -150;
                UE_LOG(LogTemp, Warning, TEXT("You're going to make me dizzy."))
            }
            if(TargetRotation.Yaw > 150)
            {
                TargetRotation.Yaw = 150;
                
                UE_LOG(LogTemp, Warning, TEXT("Woah! Slow down there."));
            }
            else if(TargetRotation.Yaw < -150)
            {
                TargetRotation.Yaw = -150;
                UE_LOG(LogTemp, Warning, TEXT("Woah! Slow down there."));
            }
            
        }
        if(!TargetRotation.IsZero())
        {
            FQuat XRotation = FQuat(FVector::UpVector, TargetRotation.Yaw * DeltaSeconds / 100);
            FQuat YRotation = FQuat(FVector::LeftVector, TargetRotation.Pitch * DeltaSeconds / 100);
            FQuat CurrentQuat = PossessedShip->GetActorQuat();
            FQuat TargetQuat = CurrentQuat * XRotation * YRotation;
            PossessedShip->SetActorRotation(TargetQuat);
        }
        /*if(!MovementInput.IsZero())
        {
            FVector NormalisedMovement = MovementInput.GetSafeNormal();
            FVector CurrentLocation = PossessedShip->GetActorLocation();
            FVector NextLocation = CurrentLocation + NormalisedMovement * PossessedShip->MovementSpeed * DeltaSeconds;
            PossessedShip->SetActorLocation(NextLocation);
            if(!RotationInput.IsZero())
            {
                FRotator CurrentRotation = PossessedShip->GetActorRotation();
                FRotator Rotation = FRotator(0, RotationInput.Y, 0);
                FRotator NextRotation = CurrentRotation + Rotation * 100 * DeltaSeconds;
                PossessedShip->SetActorRotation(NextRotation);
            }
        }*/
    }
    
}


void ASpaceshipPlayerController::MoveRightStart()
{
    RotationInput.X += 1;
    UE_LOG(LogTemp, Warning, TEXT("Right we go!"));
}

void ASpaceshipPlayerController::MoveRightEnd()
{
    UE_LOG(LogTemp, Warning, TEXT("Nevermind..."));
    RotationInput.X -= 1;
}

void ASpaceshipPlayerController::MoveLeftStart()
{
    RotationInput.X -= 1;
    UE_LOG(LogTemp, Warning, TEXT("Left we go!"));
}

void ASpaceshipPlayerController::MoveLeftEnd()
{
    RotationInput.X += 1;
    UE_LOG(LogTemp, Warning, TEXT("Nevermind..."));
}

/*void ASpaceshipPlayerController::MoveForwardStart()
{
    MovementInput.X += 1;
}

void ASpaceshipPlayerController::MoveForwardEnd()
{
    MovementInput.X -= 1;
}

void ASpaceshipPlayerController::MoveBackwardStart()
{
    MovementInput.X -= 1;
}

void ASpaceshipPlayerController::MoveBackwardEnd()
{
    MovementInput.X += 1;
}*/

void ASpaceshipPlayerController::MoveUpStart()
{
    RotationInput.Y += 1;
    UE_LOG(LogTemp, Warning, TEXT("Up we go!"));
}

void ASpaceshipPlayerController::MoveUpEnd()
{
    RotationInput.Y -= 1;
    UE_LOG(LogTemp, Warning, TEXT("Nevermind..."));
}

void ASpaceshipPlayerController::MoveDownStart()
{
    RotationInput.Y -= 1;
    UE_LOG(LogTemp, Warning, TEXT("Down we go!"));
}

void ASpaceshipPlayerController::MoveDownEnd()
{
    RotationInput.Y += 1;
    UE_LOG(LogTemp, Warning, TEXT("Nevermind..."));
}

void ASpaceshipPlayerController::ThrusterOn()
{
    Thruster = true;
}

void ASpaceshipPlayerController::ThrusterOff()
{
    Thruster = false;
}

/*
void ASpaceshipPlayerController::ShieldCooldown()
{
    if (--CoolDownRemaining <=0)
    {
        GetWorldTimerManager().ClearTimer(ShieldTimerHandle);
    }
    else 
    {
        GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Orange, "Counting down to explosion: " + FString::FromInt(CoolDownRemaining));
    }
} */

void ASpaceshipPlayerController::FireLaser()
{
    if(PossessedShip)
    {
     PossessedShip->SpawnLaser();
    }
}
void ASpaceshipPlayerController::ShieldCooldown()
{
    if (--CoolDownRemaining <= 0)
    {
        GetWorldTimerManager().ClearTimer(ShieldTimerHandle);
    }
    
}

void ASpaceshipPlayerController::FireShield()
{
    if(PossessedShip)
    {
        if(CoolDownRemaining <= 0) {
            PossessedShip->SpawnShield();
            CoolDownRemaining = 29;
            GetWorldTimerManager().SetTimer(ShieldTimerHandle, this, &ASpaceshipPlayerController::ShieldCooldown, 1.0f, true, 1.0f);
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, "Seconds till new shield: " + FString::FromInt(CoolDownRemaining));
        }
    }
        }


/*void ASpaceshipPlayerController::RotateLeftStart()
{
    RotationInput.Y -= 1;
}

void ASpaceshipPlayerController::RotateLeftEnd()
{
    RotationInput.Y += 1;
}

void ASpaceshipPlayerController::RotateRightStart()
{
    RotationInput.Y += 1;
}

void ASpaceshipPlayerController::RotateRightEnd()
{
    RotationInput.Y -= 1;
}*/



void ASpaceshipPlayerController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

    if(Input && Subsystem)
    {
        Subsystem->AddMappingContext(SpaceshipControls, 0);
        /*Input->BindAction(ForwardAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::MoveForwardStart);
        Input->BindAction(ForwardAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::MoveForwardEnd);


        Input->BindAction(BackwardAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::MoveBackwardStart);
        Input->BindAction(BackwardAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::MoveBackwardEnd);*/

        Input->BindAction(RightAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::MoveRightStart);
        Input->BindAction(RightAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::MoveRightEnd);

        Input->BindAction(LeftAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::MoveLeftStart);
        Input->BindAction(LeftAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::MoveLeftEnd);

        Input->BindAction(UpAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::MoveUpStart);
        Input->BindAction(UpAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::MoveUpEnd);

        Input->BindAction(DownAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::MoveDownStart);
        Input->BindAction(DownAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::MoveDownEnd);

        /*Input->BindAction(RotateRightAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::RotateRightStart);
        Input->BindAction(RotateRightAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::RotateRightEnd);

        Input->BindAction(RotateLeftAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::RotateLeftStart);
        Input->BindAction(RotateLeftAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::RotateLeftEnd);*/

        Input->BindAction(ThrusterAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::ThrusterOn);
        Input->BindAction(ThrusterAction, ETriggerEvent::Completed, this, &ASpaceshipPlayerController::ThrusterOff);

        Input->BindAction(LaserAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::FireLaser);

        Input->BindAction(ShieldAction, ETriggerEvent::Started, this, &ASpaceshipPlayerController::FireShield);
        
    }
    

}
