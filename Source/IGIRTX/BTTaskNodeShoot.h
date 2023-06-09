// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskNodeShoot.generated.h"

/**
 * 
 */
UCLASS()
class IGIRTX_API UBTTaskNodeShoot : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTTaskNodeShoot();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)override;

};
