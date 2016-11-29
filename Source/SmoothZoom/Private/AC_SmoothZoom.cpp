// Fill out your copyright notice in the Description page of Project Settings.

#include "SmoothZoomPrivatePCH.h"
#include "SmoothZoom.h"
#include "AC_SmoothZoom.h"

DEFINE_LOG_CATEGORY(ZoomLog);

// Sets default values for this component's properties
UAC_SmoothZoom::UAC_SmoothZoom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CurrentVersion = 1.00f;
}

// Called when the game starts
void UAC_SmoothZoom::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void UAC_SmoothZoom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (DesiredArmLength >= MinTargetLength && DesiredArmLength <= MaxTargetLength)
	{
		SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, DesiredArmLength, DeltaTime, ZoomSmoothness);
	}
}

// Assigns the SpringArm component
void UAC_SmoothZoom::SetSpringArmComponent(USpringArmComponent* AssignedSpringArm) { SpringArm = AssignedSpringArm; }

// Sets the DesiredArmLength and displays log if bDebug is true
void UAC_SmoothZoom::SmoothCameraZoom(float ZoomUnits)
{
	if (SpringArm)
	{
		DesiredArmLength = SpringArm->TargetArmLength + ZoomUnits;
		if (DesiredArmLength > MaxTargetLength) { DesiredArmLength = MaxTargetLength; }
		if (DesiredArmLength < MinTargetLength) { DesiredArmLength = MinTargetLength; }
	}
	if (bDebug)
	{
		UE_LOG(ZoomLog, Warning, TEXT("Min: %f Max: %f Desired: %f Actual: %f ZoomUnits: %f"),
			MinTargetLength, MaxTargetLength, DesiredArmLength, SpringArm->TargetArmLength, ZoomUnits)
	}
}