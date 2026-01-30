#pragma once

#include "CoreMinimal.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Base.h"
#include "UW_VehicleHUDComp_TurretElvGauge.generated.h"

UCLASS()
class BATTLESERIES2_API UUW_VehicleHUDComp_TurretElvGauge : public UUW_VehicleHUDComp_Base
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Img_Gauge = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Img_Arrow = nullptr;

	UFUNCTION(BlueprintCallable)
	void UpdateElevationGauge(float CurrentPitch, float MinPitch, float MaxPitch);
};