// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"


void AShooterPlayerController::GameHasEnded(AActor *EndGameFocus, bool bIsWinner)
{
    Super::GameHasEnded(EndGameFocus,bIsWinner);
    
    UUserWidget* LoseScreen = CreateWidget(this,LoseScreenclass);
    if(LoseScreen != nullptr)
    {
        LoseScreen->AddToViewport();
    }
    
    
    GetWorldTimerManager().SetTimer(TimerHandle,this,&APlayerController::RestartLevel,RestartDelay);
}

void AShooterPlayerController::GameWon()
{
    GameHasEnded(this,true);
}

void AShooterPlayerController::BeginPlay()
{
    UUserWidget* CC = CreateWidget(this,Corsair);
    if(CC != nullptr)
    {
        CC->AddToViewport();
    }
}
