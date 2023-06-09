// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "DoorActor.generated.h"


UCLASS()
class IGIRTX_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorActor();

	void OnInteract();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool IsDoorClosed = true;

	float RotationAngle = 90.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* Frame;
	
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* Door;


protected:

	FTimeline Timeline;

	UPROPERTY(EditAnyWhere)
	UCurveFloat* CurveFloata;

	bool bIsDoorClosed = true;

	UPROPERTY(EditAnyWhere)
	float DoorAngle = 90.f;

	UFUNCTION()
	void OpenDoor(float Value);

};
