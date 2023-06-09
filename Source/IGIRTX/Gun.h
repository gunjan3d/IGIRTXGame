// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class IGIRTX_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void Shoot();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

	UPROPERTY(VisibleAnywhere)
	class USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* Gun;

	UPROPERTY(EditAnywhere,meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere,meta = (AllowPrivateAccess = "true"))
	class UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere)
	float MaxRange = 10000.f;


	UPROPERTY(EditAnywhere)
	float Damage = 30.f;

	bool GunTrace(FHitResult& Hit,FVector & ShotDirection);

	AController* GetOwnerController();
	
	UPROPERTY(EditAnywhere)
	class USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
	class USoundBase* ImpactSound;
};
