#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "VehicleTypeDefinitions.generated.h"

enum class E_VehicleType : uint8;

//defines traits of a vehicle type

USTRUCT(BlueprintType)
struct FVehicleTypeDefintion
{
	GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    E_VehicleType VehicleType;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText DisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText Description;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSoftObjectPtr<UTexture2D> TypeIcon;                //minimap?

    //default seat count?
    //default turrets, weapons, etc?
};

UCLASS(BlueprintType)
class BATTLESERIES2_API UDA_VehicleTypeDefintion : public UDataAsset
{
    GENERATED_BODY()

public:
    //change da to a map (key = vehicle type)? (make it all 1 da in other words)
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FVehicleTypeDefintion VehicleTypeDefintion;
};