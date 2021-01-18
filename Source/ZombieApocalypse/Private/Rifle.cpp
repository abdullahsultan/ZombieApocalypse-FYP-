// Fill out your copyright notice in the Description page of Project Settings.


#include "Rifle.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ARifle::ARifle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add(TEXT("TheRifle"));
}

// Called when the game starts or when spawned
void ARifle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARifle::SetRifleMesh(USkeletalMeshComponent *Mesh)
{
	GunMesh = Mesh;
}


void ARifle::Fire(FVector FireDirection, bool IsRightClick)
{
	SocketLocation = GunMesh->GetSocketLocation("MuzzleFlashSocket");
	SocketRotation = GunMesh->GetSocketRotation("MuzzleFlashSocket");
	
	if (IsRightClick)
	{
		SocketRotation = UKismetMathLibrary::FindLookAtRotation(SocketLocation,FireDirection);
	}

	ABullet* SpawnedBullet = GetWorld()->SpawnActor<ABullet>(
		Bullet,
		SocketLocation,
		SocketRotation);

	
	SpawnedBullet->FireInDirection();
}






/*

	ABullet *SpawnedBullet = GetWorld()->SpawnActor<ABullet>(
						Bullet,
						SocketLocation,
						SocketRotation);



	
	FTransform trans;
	trans.SetLocation(SocketLocation);
	trans.SetRotation(SocketRotation.Quaternion());
	ABullet* SpawnedBullet = GetWorld()->SpawnActorDeferred<ABullet>(
		Bullet,
		trans,
		this,
		GetWorld()->GetFirstPlayerController()->GetPawn(),
		ESpawnActorCollisionHandlingMethod::AlwaysSpawn
	);*/