// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Core/UI/UW_Customization.h"
#include "LoadoutPreviewStage.h"
#include "PlayerController_Base.generated.h"

/**
 * 
 */
UCLASS()
class BATTLESERIES2_API APlayerController_Base : public APlayerController
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "HUD | Customization")
	void Init_CustomizationScreen();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD | Customization")
	TSubclassOf<UUW_Customization> CustomizationWidgetClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<ALoadoutPreviewStage> PreviewStageClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FTransform PreviewSpawnTransform;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD | Customization")
	UUW_Customization* CustomizationWidget;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	ALoadoutPreviewStage* PreviewStageActor;




	
};
