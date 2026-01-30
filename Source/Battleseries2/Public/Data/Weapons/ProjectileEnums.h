#pragma once

#include "CoreMinimal.h"
#include "ProjectileEnums.generated.h"

//rename stuff to munition?

UENUM(BlueprintType)
enum class EProjectileType : uint8
{
	Bullet					UMETA(DisplayName = "Bullet"),		//sim		init velocity set by weapon muzzle velocity
	Pellet					UMETA(DisplayName = "Pellet"),		//sim		init velocity set by weapon muzzle velocity
	Shell					UMETA(DisplayName = "Shell"),		//sim		init velocity set by weapon muzzle velocity
	Rocket					UMETA(DisplayName = "Rocket"),		//actor		init velocity comes from self
	Missile					UMETA(DisplayName = "Missile"),		//actor		init velocity comes from self
	Bomb					UMETA(DisplayName = "Bomb")			//actor
};

UENUM(BlueprintType)
enum class EProjectileLimit : uint8
{
	NoLimits				UMETA(DisplayName = "Default/No Limits"),
	LimitedTime				UMETA(DisplayName = "Limited Life Span/Time"),
	LimitedRange			UMETA(DisplayName = "Limited Range")
};

UENUM(BlueprintType)
enum class EDetonationType : uint8
{
	DetOnImpact							UMETA(DisplayName = "Detonate On Impact"),
	Airbust								UMETA(DisplayName = "Airburst"),
	Delay								UMETA(DisplayName = "Delay")
};

UENUM(BlueprintType)				//(What CAUSES the munition to change stage)
enum class ETransitionCondition : uint8
{
	OnImpact					UMETA(DisplayName = "On Impact"),
	LimitedTime					UMETA(DisplayName = "Limited Time"),
	LimitedRange				UMETA(DisplayName = "Limited Range"),
	RangeToTarget				UMETA(DisplayName = "Range To Target"),
	TargetAcquired				UMETA(DisplayName = "Target Acquired")
};

UENUM(BlueprintType)				//(What FAILURE causes the munition to change stage)
enum class EContingencyType : uint8
{
	None						UMETA(DisplayName = "None"),
	LockLost					UMETA(DisplayName = "Lock Lost"),
	OutOfFuel					UMETA(DisplayName = "Out Of Fuel"),
	MaxLifeSpanExceeded			UMETA(DisplayName = "Life Span Exceeded")
};

UENUM(BlueprintType)							//what the munition does
enum class EProjectileGuidanceMethod : uint8
{
	// Simple/Uncontrolled
	BallisticTrajectory         UMETA(DisplayName = "Default/Ballistic"),			//embedded actor data i guess

	//GUIDANCE METHOD
	// Simple Guidance (Passive / Fire & Forget)
	BoostThrust                 UMETA(DisplayName = "Thrust/Initial Acceleration"),			//good 
	TopAttack                   UMETA(DisplayName = "Top Attack Profile"),
	LockOn_FireForget           UMETA(DisplayName = "LockOn: Fire & Forget"),

	// Complex Guidance (Active Player Input/Control)
	LockOn_MaintainLock         UMETA(DisplayName = "LockOn: Maintain Lock"),
	WireGuided                  UMETA(DisplayName = "Player Controlled: Wire Guided"),
	FullControl					UMETA(DisplayName = "Player Controlled: Full Control"),

	// Terminal Behavior
	SelfDestruct                UMETA(DisplayName = "Self-Destruct")
};