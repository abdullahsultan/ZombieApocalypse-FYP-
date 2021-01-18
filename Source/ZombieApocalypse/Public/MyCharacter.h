// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Rifle.h"
#include "MyCharacter.generated.h"

UCLASS()
class ZOMBIEAPOCALYPSE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Projectile class to spawn.
	UPROPERTY(EditAnywhere, Category = Projectile)
		ABullet* ProjectileClass;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void GetSkeletalMesh(USkeletalMeshComponent *CharaterMesh);

	void SetAimDirection(FVector Aim);

	UFUNCTION(BlueprintCallable)
		void Fire();

	UFUNCTION(BlueprintCallable)
	void AimCameraPosition();

	UFUNCTION(BlueprintCallable)
		void ResetAimCameraPosition();

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<ARifle> TheRifle;


	UPROPERTY(BlueprintReadWrite)
		bool IsRightClick = false;


	ARifle* MyRifle;

	FVector GunSpawnLocation;
	FRotator GunSpawnRotation;


	UPROPERTY(BlueprintReadOnly)
	FVector AimDirection;
};
