#include "Core/UI/VehicleHUDs/UW_VehicleHUDComp_TurretLines.h"
#include "Components/Image.h"
#include "Blueprint/WidgetTree.h"

void UUW_VehicleHUDComp_TurretLines::NativeConstruct()
{
	WidgetTree->ForEachWidget([&](UWidget* Widget) 
	{
        if (UImage* Image = Cast<UImage>(Widget))
        {
            if (Image->GetName().Contains(TEXT("TurretLine")))
            {
                TurretLines.Add(Image);
            }
        }
    });
}

void UUW_VehicleHUDComp_TurretLines::UpdateTurretLinePosition(int32 TurretIndex, float RelativeYaw)
{
	UImage* TargetLine = TurretLines[TurretIndex];
	TargetLine->SetRenderTransformAngle(RelativeYaw);
}
