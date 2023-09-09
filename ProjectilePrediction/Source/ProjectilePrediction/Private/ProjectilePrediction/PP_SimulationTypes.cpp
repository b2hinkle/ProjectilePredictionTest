#include "ProjectilePrediction/PP_SimulationTypes.h"

FProjectileSimulationData::FProjectileSimulationData()
{

}

FProjectileSimulationData::FProjectileSimulationData(FVector inLocation, FVector inVelocity)
{
    Location = inLocation;
    Velocity = inVelocity;
}

bool FProjectileSimulationData::IsValid()
{
    return Velocity.Length() != 0.f; // TODO: This was made up super quick. Need to do something better.
}
