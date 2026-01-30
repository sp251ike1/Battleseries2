#pragma once

#include "CoreMinimal.h"
#include "ChaosWheeledVehicleMovementComponent.h"	
#include "ChaosWheel_Base.generated.h"

struct FBaseWheelData;

UCLASS()
class BATTLESERIES2_API UChaosWheel_Base : public UChaosVehicleWheel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Init_Wheel(const FBaseWheelData& WheelData);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool GetbAffectedBySteering();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxSteerAngle();

	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
	virtual void Init(class UChaosWheeledVehicleMovementComponent* InVehicleSim, int32 InWheelIndex) override;
};