#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_WeaponStatus.h"
#include "Components/TextBlock.h"

void UUW_VehicleHUDComp_WeaponStatus::UpdateWeapon(FText WeaponName, FText WeaponStatus)
{
	T_WeaponName->SetText(WeaponName);
	T_WeaponStatus->SetText(WeaponStatus);
}

void UUW_VehicleHUDComp_WeaponStatus::UpdateWeaponStatus(FText WeaponStatus)
{
	T_WeaponStatus->SetText(WeaponStatus);
}
