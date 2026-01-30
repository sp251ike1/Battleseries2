#include "Factories/Factory_DA_Vehicle.h"
#include "Battleseries2/Public/Data/Vehicles/DA_Vehicle.h"

UFactory_DA_Vehicle::UFactory_DA_Vehicle(const FObjectInitializer& objectInitializer) : Super(objectInitializer)
{
	SupportedClass = UDA_Vehicle::StaticClass();
}

UObject* UFactory_DA_Vehicle::FactoryCreateNew(UClass* uclass, UObject* inParent, FName name, EObjectFlags flags, UObject* context, FFeedbackContext* warn)
{
	UDA_Vehicle* createdAsset = NewObject<UDA_Vehicle>(inParent, uclass, name, flags);
	return createdAsset;
	
}

bool UFactory_DA_Vehicle::CanCreateNew() const
{
	return true;
}
