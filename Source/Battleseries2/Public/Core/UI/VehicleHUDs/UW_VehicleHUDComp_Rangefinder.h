#pragma once

#include "CoreMinimal.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Base.h"
#include "UW_VehicleHUDComp_Rangefinder.generated.h"

UCLASS()
class BATTLESERIES2_API UUW_VehicleHUDComp_Rangefinder : public UUW_VehicleHUDComp_Base
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* T_Rangefinder;

	UFUNCTION(BlueprintCallable)
	void UpdateRangefinder(float NewRange);
};
