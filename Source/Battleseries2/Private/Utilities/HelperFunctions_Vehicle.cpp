#include "Utilities/HelperFunctions_Vehicle.h"

void UHelperFunctions_Vehicle::ConvertNamesToVehicleTypes(const TArray<FName>& VehicleTypeNames, TArray<E_VehicleType>& OutVehicleTypes)
{
	OutVehicleTypes.Empty();
	for (const FName& VehicleTypeName : VehicleTypeNames)
	{
		//FString VehicleTypeString = RowName.ToString();

		//E_VehicleType VehicleType = E_VehicleType::VE_None; //default/fallback
		
		int64 FoundEnum = StaticEnum<E_VehicleType>()->GetValueByName(VehicleTypeName);
		if (FoundEnum != INDEX_NONE)
		{
			OutVehicleTypes.Add(static_cast<E_VehicleType>(FoundEnum));
			//return FoundEnum;
		}
		
	}
}

FString UHelperFunctions_Vehicle::GetVehicleTypeLiteralString(E_VehicleType VehicleType)
{
	// Use StaticEnum to look up the name
	UEnum* EnumPtr = StaticEnum<E_VehicleType>();
	if (!EnumPtr)
	{
		return FString("Invalid");
	}

	// Get the literal enum name (e.g. "IFV", "Tank", etc.)
	return EnumPtr->GetNameStringByValue(static_cast<int64>(VehicleType));
}



