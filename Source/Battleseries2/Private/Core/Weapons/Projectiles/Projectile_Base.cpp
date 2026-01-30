#include "Core/Weapons/Projectiles/Projectile_Base.h"
#include "Data/Weapons/Data_Projectile.h"
#include "Utilities/DataManagerSubsystem.h"
#include "Utilities/GameInstance_Base.h"
#include "Kismet/GameplayStatics.h"

AProjectile_Base::AProjectile_Base()
{
	ProjectileMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMeshComponent"));
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetAutoActivate(false);				//<---should this really be in the constructor????
	RootComponent = ProjectileMeshComponent;
}

void AProjectile_Base::SetProjectileAndInit(FName InputProjectileID, bool ActivateImmediately)
{
	ProjectileState.ProjectileID = InputProjectileID;
	Init_ProjectileData();
}

void AProjectile_Base::Init_ProjectileData()
{
	UDataManagerSubsystem* DataManager = GetGameInstance()->GetSubsystem<UDataManagerSubsystem>();
	const FProjectileData* ProjectileRow = DataManager->GetProjectileDataRow(ProjectileState.ProjectileID);
	ProjectileData = ProjectileRow;

	TArray<FSoftObjectPath> AssetsToLoad;
	AssetsToLoad.Add(ProjectileData->ProjectileVisualData.ProjectileMesh.ToSoftObjectPath());

	FStreamableManager* StreamableManager = Cast<UGameInstance_Base>(UGameplayStatics::GetGameInstance(this))->GetStreamableManager();
	StreamableManager->RequestAsyncLoad(AssetsToLoad, FStreamableDelegate::CreateUObject(this, &AProjectile_Base::Init_Projectile));
}

void AProjectile_Base::Init_Projectile()
{
	Init_ProjectileMesh(ProjectileData->ProjectileVisualData.ProjectileMesh.Get());
	Init_ProjectileFlightData();
}

void AProjectile_Base::Init_ProjectileMesh(UStaticMesh* LoadedProjectileMesh)
{
	ProjectileMeshComponent->SetStaticMesh(LoadedProjectileMesh);
	ProjectileMeshComponent->SetSimulatePhysics(false);				//how are we handling physics sims for projectiles in general? (prototype in bp i guess)
}

void AProjectile_Base::Init_ProjectileFlightData()
{
	switch (ProjectileData->ProjectileFlightPlan[0].BehaviorType)
	{
		case EProjectileGuidanceMethod::BallisticTrajectory:
			ProjectileMovementComponent->InitialSpeed = ProjectileState.CurrentVelocity.Size();
			ProjectileMovementComponent->MaxSpeed = ProjectileData->ProjectileFlightPlan[0].GuidanceParams.MaxSpeed;
			break;
	}
}

void AProjectile_Base::SetRuntimeContext(UPrimitiveComponent* AttachComponent, FName AttachSocket)
{
	UE_LOG(LogTemp, Warning, TEXT("[Projectile_Base::SetRuntimeContext] function begin"));
	if (AttachComponent)
	{
		this->AttachToComponent(AttachComponent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), AttachSocket);
		ProjectileState.PreFlightContext.AttachedComponent = AttachComponent;
		ProjectileState.PreFlightContext.AttachSocket = AttachSocket;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("[Projectile_Base::SetRuntimeContext] AttachComponent invalid, should detach happen here?"));
		ProjectileState.PreFlightContext.AttachedComponent = nullptr;
		ProjectileState.PreFlightContext.AttachSocket = NAME_None;
	}
}

void AProjectile_Base::FireProjectile()
{
	if (ProjectileState.PreFlightContext.AttachedComponent || GetParentComponent() != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("[ProjectilePoolSubsystem::ReturnProjectileToPool] DetachFromActor"));
		DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	}

  	switch (ProjectileData->ProjectileFlightPlan[0].BehaviorType)
	{
		case EProjectileGuidanceMethod::BallisticTrajectory:
			const FVector LaunchDir = GetActorForwardVector();
			ProjectileMovementComponent->Velocity = LaunchDir * ProjectileData->ProjectileFlightPlan[0].GuidanceParams.InitialSpeed;
			ProjectileMovementComponent->Activate();
			break;
	}
	//something something start flight plan
}

void AProjectile_Base::OnImpact()
{
}

