#pragma once

#include "CoreMinimal.h"
#include "PP_SimulationTypes.generated.h"

USTRUCT()
struct PROJECTILEPREDICTION_API FProjectileSimulationData
{
	GENERATED_BODY()

public:
	FProjectileSimulationData();

	FProjectileSimulationData(FVector inLocation, FVector inVelocity);

	bool IsValid();

	FVector Location = FVector::ZeroVector;

	FVector Velocity = FVector::ZeroVector;
};
