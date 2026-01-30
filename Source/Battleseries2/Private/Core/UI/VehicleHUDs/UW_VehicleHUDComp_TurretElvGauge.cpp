#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_TurretElvGauge.h"
#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"

void UUW_VehicleHUDComp_TurretElvGauge::UpdateElevationGauge(float CurrentPitch, float MinPitch, float MaxPitch)
{
	float GaugeHeight = Img_Gauge->GetCachedGeometry().GetLocalSize().Y;
	float HalfHeight = GaugeHeight * 0.5f;									//<--cache on construct?
	float TargetY = FMath::GetMappedRangeValueClamped(FVector2D(MinPitch, MaxPitch), FVector2D(HalfHeight, -HalfHeight), CurrentPitch);
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Img_Arrow->Slot);
	CanvasSlot->SetPosition(FVector2D(CanvasSlot->GetPosition().X, TargetY));
}
