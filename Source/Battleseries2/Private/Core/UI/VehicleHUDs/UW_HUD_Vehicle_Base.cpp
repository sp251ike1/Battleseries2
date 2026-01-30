#include "Core/UI/VehicleHUDs/UW_HUD_Vehicle_Base.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Base.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Reticle.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Rangefinder.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_WeaponStatus.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Compass.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_TurretLines.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_TurretElvGauge.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_TurretPitchMeter.h"
#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Speedometer.h"
#include "Utilities/I_HUDUpdates.h"
#include "Core/UI/VehicleHUDs/UW_HUD_Vehicle_Base.h"
#include "Blueprint/WidgetTree.h"

void UUW_HUD_Vehicle_Base::NativeConstruct()
{
	Super::NativeConstruct();
	BindComponents();
}

void UUW_HUD_Vehicle_Base::BindComponents()
{
	WidgetTree->ForEachWidget([&](UWidget* Widget)
	{
		if (UUW_VehicleHUDComp_Reticle* ReticleComp = Cast<UUW_VehicleHUDComp_Reticle>(Widget))
		{
			VehicleWeaponReticle = ReticleComp;
		}
		else if (UUW_VehicleHUDComp_WeaponStatus* StatusComp = Cast<UUW_VehicleHUDComp_WeaponStatus>(Widget))
		{
			VehicleWeaponStatus = StatusComp;
		}
		else if (UUW_VehicleHUDComp_Rangefinder* RangefinderComp = Cast<UUW_VehicleHUDComp_Rangefinder>(Widget))
		{
			Rangefinder = RangefinderComp;
		}
		else if (UUW_VehicleHUDComp_Compass* CompassComp = Cast<UUW_VehicleHUDComp_Compass>(Widget))
		{
			Compass = CompassComp;
		}
		else if (UUW_VehicleHUDComp_TurretLines* TurretLinesComp = Cast<UUW_VehicleHUDComp_TurretLines>(Widget))
		{
			TurretLines = TurretLinesComp;
		}
		else if (UUW_VehicleHUDComp_TurretElvGauge* TurretElvGaugeComp = Cast<UUW_VehicleHUDComp_TurretElvGauge>(Widget))
		{
			TurretElvGauge = TurretElvGaugeComp;
		}
		else if (UUW_VehicleHUDComp_TurretPitchMeter* TurretPitchMeterComp = Cast<UUW_VehicleHUDComp_TurretPitchMeter>(Widget))
		{
			TurretPitchMeter = TurretPitchMeterComp;
		}
		else if (UUW_VehicleHUDComp_Speedometer* SpeedometerComp = Cast<UUW_VehicleHUDComp_Speedometer>(Widget))
		{
			Speedometer = SpeedometerComp;
		}
	});
}


