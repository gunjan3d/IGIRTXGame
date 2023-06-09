// Fill out your copyright notice in the Description page of Project Settings.

#include "DoorActor.h"
#include "Components/TimelineComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADoorActor::ADoorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Frame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Frame"));
	Frame->SetupAttachment(RootComponent);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(Frame);
}



// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
	FOnTimelineFloat TimeLineProgress;
	TimeLineProgress.BindDynamic(this,&ADoorActor::OpenDoor);
	Timeline.AddInterpFloat(CurveFloata,TimeLineProgress);

}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timeline.TickTimeline(DeltaTime);
}

void ADoorActor::OpenDoor(float Value)
{
	FRotator Rot = FRotator(0.f,DoorAngle* Value,0.f);

	Door->SetRelativeRotation(Rot);
}

void ADoorActor::OnInteract()
{
	if (bIsDoorClosed)
	{
		/* code */
		Timeline.Play();
	}
	else
	{
		Timeline.Reverse();
	}
	bIsDoorClosed = !bIsDoorClosed;
}