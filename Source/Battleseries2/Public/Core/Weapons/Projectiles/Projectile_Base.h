#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Data/Runtime/ProjectileTypes.h"
#include "Projectile_Base.generated.h"
struct FProjectileData;
struct FProjectile_Runtime;

UCLASS()
class BATTLESERIES2_API AProjectile_Base : public APawn
{
	GENERATED_BODY()

public:
	AProjectile_Base();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* ProjectileMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UProjectileMovementComponent* ProjectileMovementComponent;

	const FProjectileData* ProjectileData;

	//STATE
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FProjectile_Runtime ProjectileState;

	UFUNCTION(BlueprintCallable)
	void SetProjectileAndInit(FName InputProjectileID, bool ActivateImmediately);

	UFUNCTION(BlueprintCallable)
	void Init_ProjectileData();

	UFUNCTION(BlueprintCallable)
	void Init_Projectile();

	UFUNCTION(BlueprintCallable)
	void Init_ProjectileMesh(UStaticMesh* LoadedProjectileMesh);

	UFUNCTION(BlueprintCallable)
	void Init_ProjectileFlightData();

	UFUNCTION(BlueprintCallable)
	void SetRuntimeContext(UPrimitiveComponent* AttachComponent, FName AttachSocket);

	UFUNCTION(BlueprintCallable)
	void FireProjectile();
	UFUNCTION(BlueprintCallable)
	void OnImpact();

};

