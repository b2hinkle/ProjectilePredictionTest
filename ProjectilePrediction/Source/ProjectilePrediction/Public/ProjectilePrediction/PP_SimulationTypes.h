#pragma once

#include "CoreMinimal.h"
#include "PP_SimulationTypes.generated.h"

USTRUCT()
struct PROJECTILEPREDICTION_API FProjectileSimulationData
{
	GENERATED_BODY()

public:
	FProjectileSimulationData();

	FVector Location = FVector::ZeroVector;

	FVector Velocity = FVector::ZeroVector;
};
