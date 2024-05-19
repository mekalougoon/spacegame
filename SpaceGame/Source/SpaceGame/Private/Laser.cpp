// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser.h"

// Sets default values
ALaser::ALaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LaserMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserMesh"));
	RootComponent = LaserMesh;
	MaxTime = 5;
	MovementSpeed = 8000;

	LaserMesh->OnComponentBeginOverlap.AddDynamic(this, &ALaser::OnLaserOverlap);
	LaserMesh->SetGenerateOverlapEvents(true);
	LaserMesh->SetCollisionProfileName("OverlapAll");
	
}

void ALaser::OnLaserOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor && OtherActor != this)
	{
		if(OtherActor != Parent)
		{
			FTransform SpawnLocation = OtherActor->GetActorTransform();
			//FTransform SpawnLocation = FTransform(OtherActor->GetActorLocation() + FMath::RandRange(-5, 5));

			
			OtherActor->Destroy();
			Destroy();
			UE_LOG(LogTemp, Warning, TEXT("%s Laser has hit: %s"), *GetName(), *OtherActor->GetName());
			SpawnResource(SpawnLocation);
		}
	}
}

// Called when the game starts or when spawned
void ALaser::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(TimeAlive > MaxTime)
		{
	 Destroy();
		UE_LOG(LogTemp, Warning, TEXT("%s died from existing for too long"), *GetName());
		}
	TimeAlive += DeltaTime;

	FVector CurrentLocation = GetActorLocation();
    FVector ForwardVector = GetActorForwardVector();
    FVector NextLocation = CurrentLocation + ForwardVector * MovementSpeed * DeltaTime;
    SetActorLocation(NextLocation);

	
}

void ALaser::SpawnResource(FTransform SpawnLocation)
{
	int RandInt = FMath::RandRange(2, 10);
	//UE_LOG(LogTemp, Warning, TEXT("%d my random number"), RandInt);
	for(int i = 0; i < RandInt; i++)
		if (i < RandInt)
		{
			GetWorld()->SpawnActor<AAsteroid>(ResourceAsteroidClass, SpawnLocation);
			//UE_LOG(LogTemp, Warning, TEXT(" Spawned"));
			
		}
	}

