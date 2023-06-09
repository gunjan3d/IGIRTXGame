// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IGIRTXGameMode.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class IGIRTX_API AKillEmAllGameMode : public AIGIRTXGameMode
{
	GENERATED_BODY()
public:
	// AIGIRTXGameMode();
   	virtual void PawnKilled(APawn * PawnKilled)override;
private:
	void EndGame(bool bIsWinner);	
};
