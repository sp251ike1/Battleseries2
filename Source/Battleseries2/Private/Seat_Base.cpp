// Fill out your copyright notice in the Description page of Project Settings.

#include "Seat_Base.h"
#include "Vehicle_Base.h"


// Sets default values
ASeat_Base::ASeat_Base()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	WeaponLogicComponent = CreateDefaultSubobject<UWeaponLogicComponent>(TEXT("WeaponLogicComponent"));

	SpringArm->SetupAttachment(GetMesh(), FName("head"));
	Camera->SetupAttachment(SpringArm, FName("SpringEndpoint"));
	Camera->SetHiddenInGame(false);
	Camera->SetVisibility(true);
	//Camera->bCameraMeshHiddenInGame = false;
	SetActorEnableCollision(false);
}

// Called when the game starts or when spawned
void ASeat_Base::BeginPlay()
{
	Super::BeginPlay();
	//DONT CALL POST SPAWN STUFF HERE, THAT GETS CALLED BY VEHICLE

}

// Called every frame
void ASeat_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASeat_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//called when a PLAYER enters seat
//should be called AFTER seat is possessed

//here because we need to pass in THIS SEAT, not an IA action value



