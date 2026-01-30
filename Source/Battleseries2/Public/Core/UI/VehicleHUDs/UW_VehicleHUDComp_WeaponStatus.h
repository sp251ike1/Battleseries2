#pragma once

#include "CoreMinimal.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Base.h"
#include "UW_VehicleHUDComp_WeaponStatus.generated.h"

UCLASS()
class BATTLESERIES2_API UUW_VehicleHUDComp_WeaponStatus : public UUW_VehicleHUDComp_Base
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* T_WeaponName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* T_WeaponStatus;		//ready, wait

	UFUNCTION(BlueprintCallable)
	void UpdateWeapon(FText WeaponName, FText WeaponStatus);
	UFUNCTION(BlueprintCallable)
	void UpdateWeaponStatus(FText WeaponStatus);
};