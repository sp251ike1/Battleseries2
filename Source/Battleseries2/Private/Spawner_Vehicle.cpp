// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner_Vehicle.h"
#include "Vehicle_Base.h"

// Sets default values
ASpawner_Vehicle::ASpawner_Vehicle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpawner_Vehicle::BeginPlay()
{
	Super::BeginPlay();

	AVehicle_Base* SpawnedVehicle = GetWorld()->SpawnActor<AVehicle_Base>(AVehicle_Base::StaticClass());

	//SpawnedVehicle->SetVehicleAndInit(VehicleID, false);
}

// Called every frame
void ASpawner_Vehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

