// Fill out your copyright notice in the Description page of Project Settings.

#include "AC_SmoothZoom.h"
#include "SmoothZoomDeveloperSettings.h"
#include "GameFramework/SpringArmComponent.h"

DEFINE_LOG_CATEGORY(ZoomLog);

// Sets default values for this component's properties
UAC_SmoothZoom::UAC_SmoothZoom()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentVersion = 1.50f;
	const auto &SZSettings = GetMutableDefault<USmoothZoomDeveloperSettings>();
	if (SZSettings) {
		MinTargetLength = SZSettings->MinTargetLength;
		MaxTargetLength = SZSettings->MaxTargetLength;
		ZoomSmoothness = SZSettings->ZoomSmoothness;
		ZoomUnits = SZSettings->ZoomUnits;
		bDebug = SZSettings->bDebug;
	}

}

void UAC_SmoothZoom::BeginPlay() { Super::BeginPlay(); }

void UAC_SmoothZoom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!ensure(SpringArm)) { return; };
	
	// Only call when need to, saves MS's 
	if (!FMath::IsNearlyEqual(SpringArm->TargetArmLength, DesiredArmLength, 0.5f)) {
		SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, DesiredArmLength, DeltaTime, ZoomSmoothness);
	}
}

// Assigns the SpringArm component
void UAC_SmoothZoom::SetSpringArmComponent(UPARAM(ref)USpringArmComponent* AssignedSpringArm) {
	DesiredArmLength = AssignedSpringArm->TargetArmLength;
	SpringArm = AssignedSpringArm;
}

// Sets the DesiredArmLength
void UAC_SmoothZoom::SmoothCameraZoom(bool bZoomOut) {
	DesiredArmLength = bZoomOut ? SpringArm->TargetArmLength + ZoomUnits
		: SpringArm->TargetArmLength + (ZoomUnits * -1);
	if (DesiredArmLength > MaxTargetLength || DesiredArmLength < MinTargetLength) {
		DesiredArmLength = FMath::Min<float>(FMath::Max<float>(DesiredArmLength, MinTargetLength), MaxTargetLength);
	}

	if (bDebug) { SmoothZoomLog(); }
}

void UAC_SmoothZoom::SmoothZoomLog() {
	UE_LOG(ZoomLog, Log, TEXT("ArmLength: %f, Min: %f Max: %f, ZUnits: %f, Smoothness: %f"),
		DesiredArmLength, MinTargetLength, MaxTargetLength, ZoomUnits, ZoomSmoothness)
}

