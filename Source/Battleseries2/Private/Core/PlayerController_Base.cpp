// Fill out your copyright notice in the Description page of Project Settings.

#include "Core/PlayerController_Base.h"
#include "Blueprint/UserWidget.h"

void APlayerController_Base::Init_CustomizationScreen()
{
	PreviewStageActor = GetWorld()->SpawnActor<ALoadoutPreviewStage>(PreviewStageClass, PreviewSpawnTransform);
	SetViewTarget(PreviewStageActor);
	CustomizationWidget = CreateWidget<UUW_Customization>(this, CustomizationWidgetClass);
	CustomizationWidget->AddToViewport();
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(CustomizationWidget->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputMode);
	bShowMouseCursor = true;
	CustomizationWidget->Init_Customization(PreviewStageActor);
}
