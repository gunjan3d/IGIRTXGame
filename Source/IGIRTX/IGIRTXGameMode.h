// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "IGIRTXGameMode.generated.h"

UCLASS(minimalapi)
class AIGIRTXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// AIGIRTXGameMode();
   	virtual void PawnKilled(APawn * PawnKilled);	
};



