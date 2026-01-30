#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Speedometer.h"
#include "Components/TextBlock.h"

void UUW_VehicleHUDComp_Speedometer::UpdateSpeedometer(float NewSpeed)
{
	int32 NewSpeedInt = FMath::RoundToInt(NewSpeed);
	FText SpeedTxt = FText::Format(INVTEXT("{0} kph"), FText::AsNumber(NewSpeedInt));
	T_Speedometer->SetText(SpeedTxt);
}
