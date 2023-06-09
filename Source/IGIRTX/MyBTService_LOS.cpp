// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_LOS.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Controller.h"
#include "AIController.h"

UMyBTService_LOS::UMyBTService_LOS()
{
    NodeName = TEXT("LOS");
}

void UMyBTService_LOS::TickNode(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp , NodeMemory, DeltaSeconds);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    APawn* OwnerPawn = OwnerComp.GetAIOwner()->GetPawn();
    if(OwnerComp.GetAIOwner()==nullptr) return;

    if(OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn) && (FVector::Dist(OwnerPawn->GetActorLocation(), PlayerPawn->GetActorLocation()) < 5000.f))
    {
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),PlayerPawn->GetActorLocation());    
    }
    else
    {
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());

    }
}
