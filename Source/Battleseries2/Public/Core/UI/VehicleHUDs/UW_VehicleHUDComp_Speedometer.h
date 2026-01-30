#pragma once

#include "CoreMinimal.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Base.h"
#include "UW_VehicleHUDComp_Speedometer.generated.h"

UCLASS()
class BATTLESERIES2_API UUW_VehicleHUDComp_Speedometer : public UUW_VehicleHUDComp_Base
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* T_Speedometer;

	UFUNCTION(BlueprintCallable)
	void UpdateSpeedometer(float NewSpeed);
};