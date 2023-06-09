// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNodeShoot.h"
#include "AIController.h"
#include "MainC.h"

UBTTaskNodeShoot::UBTTaskNodeShoot()
{
    NodeName = TEXT("Shoot");
}



EBTNodeResult::Type UBTTaskNodeShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp,NodeMemory);

    if(OwnerComp.GetAIOwner() == nullptr) return EBTNodeResult::Failed;

    AMainC* PlayerPawn = Cast<AMainC>(OwnerComp.GetAIOwner()->GetPawn());
    
    if(PlayerPawn == nullptr) return EBTNodeResult::Failed;

    PlayerPawn->PullTrigger();

    return EBTNodeResult::Succeeded;
}

