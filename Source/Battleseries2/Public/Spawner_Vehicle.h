// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Data/Vehicles/Data_Vehicle.h"
#include "Spawner_Vehicle.generated.h"

UCLASS()
class BATTLESERIES2_API ASpawner_Vehicle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner_Vehicle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
	FName VehicleID;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
