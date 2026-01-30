#pragma once

#include "CoreMinimal.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Base.h"
#include "UW_VehicleHUDComp_TurretLines.generated.h"

UCLASS()
class BATTLESERIES2_API UUW_VehicleHUDComp_TurretLines : public UUW_VehicleHUDComp_Base
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class UImage*> TurretLines;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "Vehicle HUD")
	void UpdateTurretLinePosition(int32 TurretIndex, float RelativeYaw);




};