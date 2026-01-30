#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Data_Camo.generated.h"

USTRUCT(BlueprintType)
struct FCamoData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText CamoDisplayName = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText CamoDescription = FText();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> CamoIcon = nullptr;
};