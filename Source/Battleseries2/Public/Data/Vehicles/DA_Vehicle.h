#pragma once
//DA_Vehicle.h
#include "CoreMinimal.h"
#include "Battleseries2/Public/Data/Vehicles/Data_Vehicle.h"
#include "DA_Vehicle.generated.h"

UCLASS(BlueprintType)
class BATTLESERIES2_API UDA_Vehicle : public UDataAsset
{
	GENERATED_BODY()

	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVehicleData Vehicle_Data;

};