// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceStation.h"

// Sets default values
ASpaceStation::ASpaceStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SpaceStationBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	SpaceStationTurret = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret"));

	SpaceStationBase->SetupAttachment(RootComponent);
	SpaceStationTurret->SetupAttachment(SpaceStationBase);

}

// Called when the game starts or when spawned
void ASpaceStation::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(BulletTimerHandle, this, &ASpaceStation::SpawnLaser, 3.0f, true, 1.0f);
}

// Called every frame
void ASpaceStation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator CurrentRotation = SpaceStationTurret->GetRelativeRotation();
	FRotator Rotation = FRotator(0, 1, 0);
	FRotator NextRotation = CurrentRotation + Rotation * 100 * DeltaTime;
	SpaceStationTurret->SetRelativeRotation(NextRotation);
	
}

void ASpaceStation::SpawnLaser()
{
	if(LaserClass)
	{
		FVector CurrentLocation = SpaceStationTurret->GetRelativeLocation();
		FRotator CurrentRotation = SpaceStationTurret->GetRelativeRotation();
		FVector TurretDisplacement = FVector(100,0,0);
		TurretDisplacement = GetActorRotation().RotateVector(TurretDisplacement);
		FVector SpawnLocation = GetActorLocation() + TurretDisplacement;
		ALaser* SpawnedLaser = Cast<ALaser>(GetWorld()->SpawnActor(LaserClass, &SpawnLocation, &CurrentRotation));
		if(SpawnedLaser)
		{
			SpawnedLaser->Parent = this;
		}
	}

}
