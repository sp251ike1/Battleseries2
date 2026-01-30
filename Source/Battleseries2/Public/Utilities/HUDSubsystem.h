#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "HUDSubsystem.generated.h"

class UUW_HUD_Vehicle_Base;
class AVehicle_Base;

UCLASS(Blueprintable, BlueprintType)
class BATTLESERIES2_API UHUDSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UUW_HUD_Vehicle_Base* CurrentVehicleHUD;

    //killfeed
    //onfootreticle
    //minimap
    //scorefeed
    //ammohealth


    UFUNCTION(BlueprintCallable)
    void SpawnVehicleSeatHUD(TSubclassOf<UUserWidget> HUDClass);
    UFUNCTION(BlueprintCallable)
    void SetupVehicleDriverHUD();
    UFUNCTION(BlueprintCallable)
    void SetupVehicleGunnerHUD();
    UFUNCTION(BlueprintCallable)
    void UpdateVehicleHUD_Weapon(int32 SeatIndex);
    UFUNCTION(BlueprintCallable)
    void UpdateSpeedHUD_Vehicle();
    UFUNCTION(BlueprintCallable)
    void UpdateWeaponReticleHUD_Vehicle(UTexture2D* ImageBrush);
    UFUNCTION(BlueprintCallable)
    void UpdateRangefinderHUD_Vehicle(AVehicle_Base* ReportingVehicle, int32 SeatIndex, float NewRange);
    UFUNCTION(BlueprintCallable)
    void UpdateWeaponHUD_Vehicle(FText WeaponDisplayName, FText WeaponStatus);
    UFUNCTION(BlueprintCallable)
    void UpdateCompassHUD_Vehicle(int32 SeatIndex);
    UFUNCTION(BlueprintCallable)
    void UpdateTurretLinesHUD_Vehicle();
    UFUNCTION(BlueprintCallable)
    void UpdateTurretElevationHUD_Vehicle(int32 SeatIndex);
    UFUNCTION(BlueprintCallable)
    void HandleTurretRotationUpdate(int32 SeatIndex);
    UFUNCTION(BlueprintCallable)
    void HandleTurretPitchUpdate(int32 SeatIndex);
};