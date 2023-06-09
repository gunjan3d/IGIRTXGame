// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class IGIRTX_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;

	// UPROPERTY(EditAnywhere)
	// FVector Dis = FVector(100.f,100.f,100.f);
};
