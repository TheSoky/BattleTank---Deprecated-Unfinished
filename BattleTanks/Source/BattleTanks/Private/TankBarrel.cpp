// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame
	//Given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	float Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationInDegrees, MaxElevationInDegrees);

	SetRelativeRotation(FRotator(Elevation, 0.0f, 0.0f));
}


