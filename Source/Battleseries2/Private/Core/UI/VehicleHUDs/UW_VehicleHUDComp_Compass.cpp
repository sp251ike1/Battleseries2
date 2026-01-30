#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Compass.h"
#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"

void UUW_VehicleHUDComp_Compass::UpdateCompassPosition(float Yaw)
{
	UObject* Resource = Img_Compass->GetBrush().GetResourceObject();
	UTexture2D* CompassTex = Cast<UTexture2D>(Resource);
	float TexWidth = (float)CompassTex->GetSizeX();
	float CenterOffset = TexWidth * 0.5f;
	float NewYaw = Yaw * -1.0f * 10.0f - CenterOffset;		//2700
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Img_Compass->Slot);
	CanvasSlot->SetPosition(FVector2D(NewYaw, CanvasSlot->GetPosition().Y));
}

void UUW_VehicleHUDComp_Compass::UpdateCompassImg(UTexture2D* ImageBrush)
{
	Img_Compass->SetBrushFromTexture(ImageBrush);
}
