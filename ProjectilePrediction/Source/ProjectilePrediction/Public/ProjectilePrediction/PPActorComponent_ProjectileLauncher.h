// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PP_SimulationTypes.h"

#include "PPActorComponent_ProjectileLauncher.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTILEPREDICTION_API UPPActorComponent_ProjectileLauncher : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPPActorComponent_ProjectileLauncher();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void LaunchProjectile(const FVector inLaunchLocation, const FVector inLaunchDirection, const float inLaunchSpeed);

private:
	FProjectileSimulationData ProjectileSimulation = FProjectileSimulationData();

	FVector Gravity = FVector(0, 0, -982.f); // TODO: Need to find good place to store this kinda stuff
	float AirResistance = 300.f; // TODO: This is just some random made up value but we need to come up with a good number and also find a good place to store this along with Gravity
};
