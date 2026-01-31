#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_WeaponStatus.h"
#include "Components/TextBlock.h"

void UUW_VehicleHUDComp_WeaponStatus::UpdateWeaponName(FText WeaponName)
{
	T_WeaponName->SetText(WeaponName);
}

void UUW_VehicleHUDComp_WeaponStatus::UpdateWeaponStatus(FText WeaponStatus)
{
	T_WeaponStatus->SetText(WeaponStatus);
}
