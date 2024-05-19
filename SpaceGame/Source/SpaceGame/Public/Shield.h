// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Math/Rotator.h"
#include "GameFramework/Actor.h"
#include "Shield.generated.h"

UCLASS()
class SPACEGAME_API AShield : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShield();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ShieldMesh;
	
	
	float TimeAlive;
	float MaxTime;
	float MovementSpeed;
	float AngleAxis;
	AActor* Parent;
	


	UFUNCTION()
		void OnShieldOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool
bFromSweep, const FHitResult& SweepResult);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
