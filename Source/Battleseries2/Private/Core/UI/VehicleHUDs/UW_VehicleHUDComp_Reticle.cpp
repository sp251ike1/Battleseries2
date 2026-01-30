#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_Reticle.h"
#include "Components/Image.h"

void UUW_VehicleHUDComp_Reticle::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUW_VehicleHUDComp_Reticle::UpdateReticleImage(UTexture2D* ImageBrush)
{
	Reticle->SetBrushFromTexture(ImageBrush);
}


