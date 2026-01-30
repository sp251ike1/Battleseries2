#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Data/Weapons/Data_Weapon.h"
#include "Data_VehicleInstance.generated.h"

//ALL OF THIS DATA IS APPLIED TO THAT PARTICULAR VEHICLE (VehicleID = RowName)



USTRUCT(BlueprintType)
struct FVehicleWeaponOverrides
{
	GENERATED_BODY()

	//the following denotes what exact weapon for that specific vehicle, and where it is (seat/weapon index)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName WeaponID; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 SeatIndex;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 WeaponIndex;

	//data specific to WEAPON in that SEAT in that VEHICLE
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "WeaponIndex == 0", EditConditionHides = true))
	bool DoesWeaponHaveDedicatedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Tooltip = "The mesh for this weapon if not just part of the vehicle mesh", EditCondition = "DoesWeaponHaveDedicatedMesh && WeaponIndex == 0", EditConditionHides = true))
	TSoftObjectPtr<USkeletalMesh> WeaponMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Tooltip = "The Socket on the vehicle mesh that the weapon mesh attach to (allows for rotating like a turret)", EditCondition = "DoesWeaponHaveDedicatedMesh && WeaponIndex == 0", EditConditionHides = true))
	FName WeaponParentSocket;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "DoesWeaponHaveDedicatedMesh && WeaponIndex == 0", EditConditionHides = true))
	FTransform WeaponTransform;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (Tooltip = "Is the weapon intended to be held by the character, rather than just mounted on the vehicle", EditCondition = "DoesWeaponHaveDedicatedMesh", EditConditionHides = true))
	bool bIsHeldByCharacter;
};
