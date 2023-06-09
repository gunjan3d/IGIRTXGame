// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"
#include "BehaviorTree/BlackboardComponent.h"



void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    if(AIBehavior != nullptr)
    {
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        RunBehaviorTree(AIBehavior);
        
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());
    }
}

void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // UE_LOG(LogTemp, Warning, TEXT("%s"),*(this->GetActorNameOrLabel()));
    // APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    // APawn* Ownerpawn = AController::GetPawn();
    // if(FVector::Dist(Ownerpawn->GetActorLocation(), PlayerPawn->GetActorLocation()) < 1000.f)
    // {
// 
        // if (LineOfSightTo(PlayerPawn) &&(FVector::Dist(Ownerpawn->GetActorLocation(), PlayerPawn->GetActorLocation()) < 1000.f))
        // {
        //     GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"),PlayerPawn->GetActorLocation());
        //     GetBlackboardComponent()->SetValueAsVector(TEXT("LastKnownPlayerLocation"),PlayerPawn->GetActorLocation());

        // }
    
        // else
        // {
        //     GetBlackboardComponent()->ClearValue(TEXT("PlayerLocation"));
        // }       
    // }
  
    
    
}
