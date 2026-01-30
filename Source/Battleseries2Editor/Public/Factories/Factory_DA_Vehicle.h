#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "Factory_DA_Vehicle.generated.h"

UCLASS(BlueprintType)
class UFactory_DA_Vehicle : public UFactory
{
	GENERATED_BODY()

	public:
		UFactory_DA_Vehicle(const FObjectInitializer& objectInitializer);

		//core function that creates new asset when user clicks "Add New --> Custom Asset" in content menu
		virtual UObject* FactoryCreateNew(UClass* uclass, UObject* inParent, FName name, EObjectFlags flags, UObject* context, FFeedbackContext* warn);
		virtual bool CanCreateNew() const override;
};
