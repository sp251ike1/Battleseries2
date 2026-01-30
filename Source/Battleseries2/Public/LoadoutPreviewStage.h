// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Vehicle_Base.h"
#include "LoadoutPreviewStage.generated.h"

UCLASS()
class BATTLESERIES2_API ALoadoutPreviewStage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoadoutPreviewStage();

	//Components
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArm = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* Camera = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AVehicle_Base> VehicleClass = nullptr;
	UPROPERTY(BlueprintReadWrite)
	AVehicle_Base* CurrentVehicle = nullptr;
	UPROPERTY()
	AActor* CurrentObject = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool RotateObject = false;		//true = rotate object, false = orbit camera
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RotateSpeed = 1.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ZoomSpeed = 20.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MinZoom = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxZoom = 1500.f;

	//if we're gonna expand to not just be spawning vehicle but also regular weapons, need additional functions (consider interface)
	UFUNCTION(BlueprintCallable)
	void SetupNewPreviewVehicle(FTransform PreviewTransformOffset, FVehicleStartingData InputVehicleStartingData);

	UFUNCTION(BlueprintCallable)
	FName GetVehicleMeshRootBoneName();

	UFUNCTION(BlueprintCallable)
	void CenterCameraOnVehicle();

	UFUNCTION(BlueprintCallable)
	void RotatePreview(float DeltaYaw, float DeltaPitch);
	UFUNCTION(BlueprintCallable)
	void ZoomPreview(float DeltaZoom);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* VehicleAnchor = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
