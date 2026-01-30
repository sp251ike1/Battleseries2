#include "Core/Vehicles/ChaosWheel_Base.h"
#include "Data/Vehicles/Data_Vehicle.h"
#include "ChaosWheeledVehicleMovementComponent.h"


void UChaosWheel_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Error, TEXT("[ChaosWheel_Base::Tick] bAffectedBySteering = %d"), bAffectedBySteering);
	UE_LOG(LogTemp, Error, TEXT("[ChaosWheel_Base::Tick] bAffectedBySteering = %f"), MaxSteerAngle);
}

void UChaosWheel_Base::Init(UChaosWheeledVehicleMovementComponent* InVehicleSim, int32 InWheelIndex)
{
	Super::Init(InVehicleSim, InWheelIndex);
}

void UChaosWheel_Base::Init_Wheel(const FBaseWheelData& WheelData)
{
	CollisionMesh = WheelData.CollisionMesh;
	AxleType = WheelData.AxleType;
	Offset = WheelData.Offset;
	WheelRadius = WheelData.WheelRadius;
	WheelWidth = WheelData.WheelWidth;
	WheelMass = WheelData.WheelMass;
	CorneringStiffness = WheelData.CorneringStiffness;
	FrictionForceMultiplier = WheelData.FrictionForceMultiplier;
	SideSlipModifier = WheelData.SideSlipModifier;
	SlipThreshold = WheelData.SlipThreshold;
	SkidThreshold = WheelData.SkidThreshold;
	MaxSteerAngle = WheelData.MaxSteerAngle;
	bAffectedBySteering = WheelData.bAffectedBySteering;
	bAffectedByBrake = WheelData.bAffectedByBrake;
	bAffectedByHandbrake = WheelData.bAffectedByHandbrake;
	bAffectedByEngine = WheelData.bAffectedByEngine;
	bABSEnabled = WheelData.bABSEnabled;
	bTractionControlEnabled = WheelData.bTractionControlEnabled;
	MaxWheelspinRotation = WheelData.MaxWheelspinRotation;
	ExternalTorqueCombineMethod = WheelData.ExternalTorqueCombineMethod;
	LateralSlipGraph = WheelData.LateralSlipGraph;
	SuspensionAxis = WheelData.SuspensionAxis;
	SuspensionForceOffset = WheelData.SuspensionForceOffset;
	SuspensionMaxRaise = WheelData.SuspensionMaxRaise;
	SuspensionMaxDrop = WheelData.SuspensionMaxDrop;
	SuspensionDampingRatio = WheelData.SuspensionDampingRatio;
	WheelLoadRatio = WheelData.WheelLoadRatio;
	SpringRate = WheelData.SpringRate;
	SpringPreload = WheelData.SpringPreload;
	SuspensionSmoothing = WheelData.SuspensionSmoothing;
	RollbarScaling = WheelData.RollbarScaling;
	SweepShape = WheelData.SweepShape;
	SweepType = WheelData.SweepType;
	MaxBrakeTorque = WheelData.MaxBrakeTorque;
	MaxHandBrakeTorque = WheelData.MaxHandBrakeTorque;

	//refresh something?
}

bool UChaosWheel_Base::GetbAffectedBySteering()
{
	return bAffectedBySteering;
}

float UChaosWheel_Base::GetMaxSteerAngle()
{
	return MaxSteerAngle;
}


