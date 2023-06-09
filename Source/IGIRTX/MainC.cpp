// Fill out your copyright notice in the Description page of Project Settings.


#include "MainC.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "IGIRTXGameMode.h"
#include "DoorActor.h"
#include "Gun.h"


// Sets default values
AMainC::AMainC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraBoom->SetupAttachment(RootComponent);

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	FollowCamera->SetupAttachment(CameraBoom);
}


// Called when the game starts or when spawned
void AMainC::BeginPlay()
{
	Super::BeginPlay();
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	// GetMesh()->HideBoneByName(TEXT("Weapon_r"),EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(),FAttachmentTransformRules::KeepRelativeTransform,TEXT("hand_r"));
	Gun->SetOwner(this);
	CurrentHealth = MaxHealth;
}



// Called every frame
void AMainC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	

}

// Called to bind functionality to input
void AMainC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&AMainC::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this,&APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&AMainC::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookRight"),this,&APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"),EInputEvent::IE_Pressed,this,&ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Interact"),EInputEvent::IE_Pressed,this,&AMainC::OnInteract);
	PlayerInputComponent->BindAction(TEXT("Fire"),EInputEvent::IE_Pressed,this,&AMainC::PullTrigger);
}

void AMainC::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector() * value);
}

void AMainC::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector()*value);
}

void AMainC::OnInteract()
{
	if(FollowCamera == nullptr) return;

	FHitResult HitResult;
	FVector Start = FollowCamera->GetComponentLocation();
	FVector End = Start + FollowCamera->GetForwardVector() * 1000.f;

	GetWorld()->LineTraceSingleByChannel(HitResult,Start,End,ECollisionChannel::ECC_Visibility);

	ADoorActor* Door = Cast<ADoorActor>(HitResult.GetActor());

	if(Door)
	{
		Door->OnInteract();
	}

}



void AMainC::PullTrigger()
{
	Gun->Shoot();
}


float AMainC::TakeDamage(float DamageAmount, FDamageEvent const &DamageEvent, AController *EventInstigator, AActor *DamageCauser)
{
    float DamageToApplied = Super::TakeDamage(DamageAmount,DamageEvent,EventInstigator,DamageCauser);
	DamageToApplied = FMath::Min(CurrentHealth,DamageToApplied);

	CurrentHealth -= DamageToApplied;
	if(IsDead())
	{
		AIGIRTXGameMode* GameMode = GetWorld()->GetAuthGameMode<AIGIRTXGameMode>();
		if(GameMode != nullptr)
		{
			// GameMode->PawnKilled(this);
			GameMode->PawnKilled(this);
		}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
	}
	
	
	UE_LOG(LogTemp, Warning, TEXT("%f"),CurrentHealth);
	return DamageToApplied;
}


bool AMainC::IsDead() const
{
    return CurrentHealth<=0;
}

float AMainC::GetHealthPercent() const
{
    return CurrentHealth/MaxHealth;
}
