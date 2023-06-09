// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "MyBTService_LOS.generated.h"

/**
 * 
 */
UCLASS()
class IGIRTX_API UMyBTService_LOS : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UMyBTService_LOS();
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;	
};
