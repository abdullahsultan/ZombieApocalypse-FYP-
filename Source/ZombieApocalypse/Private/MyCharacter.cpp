// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add(TEXT("PlayerCharacter"));

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMyCharacter::Fire()
{
	MyRifle->Fire(AimDirection, IsRightClick);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void AMyCharacter::GetSkeletalMesh(USkeletalMeshComponent *CharaterMesh)
{
	GunSpawnLocation = CharaterMesh->GetSocketLocation("GunSocket");
	GunSpawnRotation = CharaterMesh->GetSocketRotation("GunSocket");

	MyRifle = GetWorld()->SpawnActor<ARifle>(
		TheRifle,
		GunSpawnLocation,
		GunSpawnRotation
		);

	
	MyRifle->AttachToComponent(
		CharaterMesh,
		FAttachmentTransformRules::FAttachmentTransformRules(
			EAttachmentRule::SnapToTarget,
			true),
			"GunSocket");
}

void AMyCharacter::SetAimDirection(FVector Aim)
{
	AimDirection = Aim;
}

void AMyCharacter::AimCameraPosition() {
	UCameraComponent* camera = FindComponentByClass<UCameraComponent>();
	camera->SetRelativeLocation(FVector(160.0f,63.0f,29.0f));
}

void AMyCharacter::ResetAimCameraPosition() {
	UCameraComponent* camera = FindComponentByClass<UCameraComponent>();
	camera->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
}