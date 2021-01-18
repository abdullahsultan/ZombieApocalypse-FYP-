// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyCharacter.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIEAPOCALYPSE_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void AimTowardsCrossHair();

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f;

	AMyCharacter *PlayerCharacter;
	
};
