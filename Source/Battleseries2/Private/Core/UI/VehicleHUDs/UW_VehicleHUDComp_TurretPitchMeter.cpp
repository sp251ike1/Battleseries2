#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_TurretPitchMeter.h"
#include "Components/TextBlock.h"

void UUW_VehicleHUDComp_TurretPitchMeter::UpdatePitchMeter(float NewPitch)
{
	int32 RoundedNewPitch = FMath::RoundToInt(NewPitch);
	FText DegreeValue = FText::Format(INVTEXT("{0}\u00B0"), FText::AsNumber(RoundedNewPitch));
	T_PitchMeter->SetText(DegreeValue);
}