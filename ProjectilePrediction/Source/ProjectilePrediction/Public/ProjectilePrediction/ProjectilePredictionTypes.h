#pragma once

#include "CoreMinimal.h"
#include "ProjectilePredictionTypes.generated.h"

USTRUCT()
struct PROJECTILEPREDICTION_API FProjectileSimulationData
{
	GENERATED_BODY()

public:
	FProjectileSimulationData();

	FVector Location = FVector::ZeroVector;

	FVector Velocity = FVector::ZeroVector;
};
