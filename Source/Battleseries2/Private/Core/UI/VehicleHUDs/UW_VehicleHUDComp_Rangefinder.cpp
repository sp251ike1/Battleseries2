#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Rangefinder.h"
#include "Components/TextBlock.h"

void UUW_VehicleHUDComp_Rangefinder::UpdateRangefinder(float NewRange)
{
	int32 NewRangeInt = FMath::RoundToInt(NewRange);
	T_Rangefinder->SetText(FText::AsNumber(NewRangeInt));
}
