#pragma once

#include "CoreMinimal.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Base.h"
#include "UW_VehicleHUDComp_Compass.generated.h"

UCLASS()
class BATTLESERIES2_API UUW_VehicleHUDComp_Compass : public UUW_VehicleHUDComp_Base
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UImage* Img_Compass = nullptr;

	UFUNCTION(BlueprintCallable)
	void UpdateCompassPosition(float Yaw);
	UFUNCTION(BlueprintCallable)
	void UpdateCompassImg(UTexture2D* ImageBrush);
};
