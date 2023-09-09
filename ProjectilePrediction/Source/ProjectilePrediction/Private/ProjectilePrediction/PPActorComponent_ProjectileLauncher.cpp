// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectilePrediction/PPActorComponent_ProjectileLauncher.h"

// Sets default values for this component's properties
UPPActorComponent_ProjectileLauncher::UPPActorComponent_ProjectileLauncher()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPPActorComponent_ProjectileLauncher::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPPActorComponent_ProjectileLauncher::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

