// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
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

};
