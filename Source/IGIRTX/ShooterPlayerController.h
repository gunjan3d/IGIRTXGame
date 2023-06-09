// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "ShooterPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class IGIRTX_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void GameHasEnded(class AActor *EndGameFocus ,bool bIsWinner)override;
	UFUNCTION(BlueprintCallable)
	void GameWon();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	float RestartDelay = 8.f;

	FTimerHandle TimerHandle;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> LoseScreenclass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UUserWidget> Corsair;

	
	
};
