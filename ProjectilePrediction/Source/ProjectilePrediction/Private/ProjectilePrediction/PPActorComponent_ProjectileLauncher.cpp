// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectilePrediction/PPActorComponent_ProjectileLauncher.h"

UPPActorComponent_ProjectileLauncher::UPPActorComponent_ProjectileLauncher()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UPPActorComponent_ProjectileLauncher::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void UPPActorComponent_ProjectileLauncher::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ProjectileSimulation.IsValid())
	{
		ECollisionChannel traceChannel = ECollisionChannel::ECC_EngineTraceChannel1;
		FCollisionQueryParams collisionQueryParams = FCollisionQueryParams();
		collisionQueryParams.bTraceComplex = true;
		FHitResult outHit = FHitResult();

		const FVector stepStart = ProjectileSimulation.Location;
		const FVector traceEnd = ProjectileSimulation.Location + ProjectileSimulation.Velocity;
		GetWorld()->LineTraceSingleByChannel(outHit, stepStart, traceEnd, traceChannel, collisionQueryParams); // TODO: How should we handle launch speed? Rn just treating it as a length.

		const FVector stepEnd = outHit.IsValidBlockingHit() ? outHit.ImpactPoint : traceEnd;
		ProjectileSimulation.Location = stepEnd;
		const FVector airResistanceVelocity = -ProjectileSimulation.Velocity.GetSafeNormal() * AirResistance;
		ProjectileSimulation.Velocity += (Gravity + airResistanceVelocity) * DeltaTime;


#if ENABLE_DRAW_DEBUG
		DrawDebugLine(GetWorld(), stepStart, stepEnd, FColor::MakeRandomColor(), false, 5.f, 0);
#endif
	}
}

void UPPActorComponent_ProjectileLauncher::LaunchProjectile(const FVector inLaunchLocation, const FVector inLaunchDirection, const float inLaunchSpeed)
{
	ProjectileSimulation = FProjectileSimulationData(inLaunchLocation, inLaunchDirection * inLaunchSpeed);
}

