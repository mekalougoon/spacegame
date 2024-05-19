// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroid.h"

#include "AsteroidSpawner.h"
#include "ResourceAsteroid.h"
#include "HomingAsteroid.h"

// Sets default values
AAsteroid::AAsteroid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AsteroidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = AsteroidMesh;
	AsteroidMesh->OnComponentBeginOverlap.AddDynamic(this, &AAsteroid::OnAsteroidOverlap);
	AsteroidMesh->SetGenerateOverlapEvents(true);
	AsteroidMesh->SetCollisionProfileName("OverlapAll");

}

void AAsteroid::OnAsteroidOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	int ShipHealth = 10;
	if(OtherActor && OtherActor != this
)
	{
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Asteroid %s has hit the ship!"), *GetName());
		if (ShipHealth > 0)
		{
			ShipHealth--;
		}
		UE_LOG(LogTemp, Warning, TEXT("Health Remaining: %d"), ShipHealth);
		//SpawnResource();
	}
	ShipHealth--;
}



// Called when the game starts or when spawned
void AAsteroid::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsteroid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/*void AAsteroid::SpawnResource()
{
		GetWorld()->SpawnActor<AAsteroid>(ResourceAsteroidClass);

}*/
