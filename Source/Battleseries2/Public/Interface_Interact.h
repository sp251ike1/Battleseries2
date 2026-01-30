// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Character_Base.h"
#include "Interface_Interact.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UInterface_Interact : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BATTLESERIES2_API IInterface_Interact
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
		// This will be overridden by classes that implement the interface
		UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Default")
		void Interact(ACharacter_Base* CharacterInteracting);

};
