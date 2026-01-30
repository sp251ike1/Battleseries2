#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "I_Anims.generated.h"

UINTERFACE(MinimalAPI)
class UAnims : public UInterface
{
	GENERATED_BODY()
};

class BATTLESERIES2_API IAnims
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Anim Interface")
	void OnUpdateTurret(float Rotation, float Pitch);

};