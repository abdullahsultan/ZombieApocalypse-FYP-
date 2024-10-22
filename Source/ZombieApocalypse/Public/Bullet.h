// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Bullet.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class ZOMBIEAPOCALYPSE_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	// Projectile movement component.
		UProjectileMovementComponent* ProjectileMovementComponent = nullptr;


	// Function that initializes the projectile's velocity in the shoot direction.
	void FireInDirection();

};
