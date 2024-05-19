// Fill out your copyright notice in the Description page of Project Settings.


#include "AsteroidSpawner.h"
#include "Spaceship.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AAsteroidSpawner::AAsteroidSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AsteroidsToSpawn = 30
;
	MaxTotalAsteroids = 200
	;
	SpawnRadius = 3000
	;
	SpawnProximity = 500
	;
	CheckTime =
	3
	;

}

void AAsteroidSpawner::OnTimedSpawn()
{
	if(PlayerShip)
	{
		
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAsteroid::StaticClass(), Asteroids);
		if(Asteroids.Num() < MaxTotalAsteroids)
			UE_LOG(LogTemp, Warning, TEXT("Asteroids now in the Map: %d"), Asteroids.Num());
		{
			int AsteroidsAround = 0;
			for(int i = 0; i < Asteroids.Num(); i++)
			{
				if(FVector::Dist(Asteroids[i]->GetActorLocation(), PlayerShip->GetActorLocation()) < SpawnRadius)
				{
					AsteroidsAround++;
					
				}
			}
			
			while(AsteroidsAround < AsteroidsToSpawn)
			{
				
				bool SpawnValid = false;
				FVector RandomSpawn;
				while(!SpawnValid)
				{
					
					RandomSpawn = FVector(PlayerShip->GetActorLocation().X + FMath::RandRange(-SpawnRadius, SpawnRadius), PlayerShip->GetActorLocation().Y +
				   FMath::RandRange(-SpawnRadius, SpawnRadius),PlayerShip->GetActorLocation().Z + FMath::RandRange(-SpawnRadius, SpawnRadius));
					SpawnValid = true;
					for(int i = 0; i < Asteroids.Num(); i++)
					{
						if(FVector::Dist(Asteroids[i]->GetActorLocation(), RandomSpawn) < SpawnProximity)
						{
							SpawnValid = false;
						}
					}
					if(FVector::Dist(PlayerShip->GetActorLocation(), RandomSpawn) < SpawnProximity)
					{
						SpawnValid = false;
					}
					
				}
				int RandInt = FMath::RandRange(1, HomingSpawnChance);
				if(RandInt == HomingSpawnChance)
				{
					GetWorld()->SpawnActor
				   (HomingAsteroidClass, &RandomSpawn);
				}
				else if(RandInt == StationSpawnChance)
				{
					GetWorld()->SpawnActor
					(SpaceStationClass, &RandomSpawn);
					
				}
				else {
					GetWorld()->SpawnActor
				   (AsteroidClass, &RandomSpawn);
					
				}
				AsteroidsAround++;
				
			}
		}
	}
}
				
// Called when the game starts or when spawned
void AAsteroidSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AAsteroidSpawner::OnTimedSpawn, CheckTime, true);
	PlayerShip = Cast<ASpaceship>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

// Called every frame
void AAsteroidSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

