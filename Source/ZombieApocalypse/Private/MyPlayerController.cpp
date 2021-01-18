// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

//BeginPlay
void AMyPlayerController::BeginPlay()
{
	PlayerCharacter = Cast<AMyCharacter>(GetCharacter());
}

// Called every frame
void AMyPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrossHair();

}


void AMyPlayerController::AimTowardsCrossHair()
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY); //Get ViewPort(BP widget) size (In our case screen size)
	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation); //Getting location of AimPoint from screen size(actullay BP widget)
	FVector LookDirection(0);
	FVector CameraWorldPosition; //Useless
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldPosition, LookDirection);
	

	FVector HitLocation; FHitResult HitObject;

	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
		HitObject,
		Start,
		End,
		ECollisionChannel::ECC_Visibility
	))
	{
		HitLocation = HitObject.Location;
	}
	else
		HitLocation = FVector(0.0f);
	PlayerCharacter->SetAimDirection(HitLocation);	
}


