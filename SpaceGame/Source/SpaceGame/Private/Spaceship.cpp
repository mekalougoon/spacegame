// Fill out your copyright notice in the Description page of Project Settings.


#include "Spaceship.h"

// Sets default values
ASpaceship::ASpaceship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SpaceshipBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	SpaceshipTurret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));
	SpaceshipBarrel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Barrel"));

	SpaceshipBase->SetupAttachment(RootComponent);
	SpaceshipTurret->SetupAttachment(SpaceshipBase);
	SpaceshipBarrel->SetupAttachment(SpaceshipTurret);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	SpringArm->SetupAttachment(SpaceshipBase);

	SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 10.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 10.0f;
	MovementSpeed = 4000.0f;

}



void ASpaceship::SpawnLaser()
{
	if(LaserClass)
    {
		UE_LOG(LogTemp, Warning, TEXT("Fired a Laser"));
     FVector CurrentLocation = GetActorLocation();
     FRotator CurrentRotation = GetActorRotation();
     FVector TurretDisplacement = FVector(100,0,60);
     TurretDisplacement = GetActorRotation().RotateVector(TurretDisplacement);
     FVector SpawnLocation = GetActorLocation() + TurretDisplacement;
     ALaser* SpawnedLaser = Cast<ALaser>(GetWorld()->SpawnActor(LaserClass, &SpawnLocation, &CurrentRotation));
     if(SpawnedLaser)
     {
     SpawnedLaser->Parent = this;
     }
    }

}

void ASpaceship::SpawnShield()
{
	if(ShieldClass)
    {
     FVector CurrentLocation = GetActorLocation();
     FRotator CurrentRotation = GetActorRotation();
		
     FVector TurretDisplacement = FVector(1000,0,0);
     TurretDisplacement = GetActorRotation().RotateVector(TurretDisplacement);
     FVector SpawnLocation = GetActorLocation() + TurretDisplacement;
     AShield* SpawnedShield = Cast<AShield>(GetWorld()->SpawnActor(ShieldClass, &SpawnLocation, &CurrentRotation));
     if(SpawnedShield)
     {
     SpawnedShield->Parent = this;
     }
    }

}

// Called when the game starts or when spawned
void ASpaceship::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

