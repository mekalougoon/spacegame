// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"

// Sets default values
AShield::AShield()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldMesh"));
	RootComponent = ShieldMesh;
	MaxTime = 1000;
	MovementSpeed = 0;
	AngleAxis = 0;


	
	ShieldMesh->OnComponentBeginOverlap.AddDynamic(this, &AShield::OnShieldOverlap);
	ShieldMesh->SetGenerateOverlapEvents(true);
	ShieldMesh->SetCollisionProfileName("OverlapAll");
	
}



void AShield::OnShieldOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                              UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor && OtherActor != this)
	{
		if(OtherActor != Parent)
		{
			OtherActor->Destroy();
			Destroy();
		} }
}

// Called when the game starts or when spawned
void AShield::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShield::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(TimeAlive > MaxTime)
	{
		Destroy();
	}
	TimeAlive += DeltaTime;


	
	FRotator CurrentRotation = GetActorRotation();
	FRotator Rotation = FRotator(0, 0.5, 0);
	FRotator NextRotation = CurrentRotation + Rotation * 100 * DeltaTime;
	SetActorRotation(NextRotation); 

	

	
	
	FVector NewLocation = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector LocationRadius = FVector( 200,200,0);
	AngleAxis++;
	
	if(AngleAxis > 360.0f) {

		AngleAxis = 1;
	}

	FVector RotateValue = LocationRadius.RotateAngleAxis(AngleAxis, FVector (0,0,1));

	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;
	
	SetActorLocation(NewLocation);
	
	
}

