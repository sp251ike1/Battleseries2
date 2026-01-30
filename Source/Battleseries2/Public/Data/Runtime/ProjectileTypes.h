#pragma once

#include "CoreMinimal.h"
#include "ProjectileTypes.generated.h"

class AStaticMeshActor;

USTRUCT(BlueprintType)
struct FProjectile_PreFlightContext
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)				// If null, this projectile is unmounted and goes to world 0 when released
	UPrimitiveComponent* AttachedComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)				// Socket or hardpoint name on the attached component
	FName AttachSocket = NAME_None;
};

USTRUCT(BlueprintType)
struct FProjectile_Runtime
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ProjectileID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AStaticMeshActor* ProjectileMesh = nullptr;

	//movement state (updated everytick)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)     //the initial location of the projectile
	FVector FireOrigin = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentVelocity = FVector();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float GravityScale = 0.0f;

	//Flight Plan State
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 CurrentStageIndex = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentStageTimer = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FProjectile_PreFlightContext PreFlightContext = FProjectile_PreFlightContext();
};
