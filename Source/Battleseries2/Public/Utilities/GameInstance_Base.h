// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"
#include "GameInstance_Base.generated.h"

class UDataManagerSubsystem;

/**
*	-top level orchestrator for session-level logic
*	-persists between maps, owns global systems, coordinates preloading, match/level transitions
*	-contains streamable manager
 */
UCLASS(Blueprintable, BlueprintType)
class BATTLESERIES2_API UGameInstance_Base : public UGameInstance
{
	GENERATED_BODY()

	FStreamableManager StreamableManager;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Subsystems")
	TSubclassOf<UDataManagerSubsystem> DataManagerSubsystemClass;
	virtual void Init() override;	

	FStreamableManager* GetStreamableManager() { return &StreamableManager; }

	UFUNCTION(BlueprintCallable)
	void StartPreMatchLoad();

private:
};
