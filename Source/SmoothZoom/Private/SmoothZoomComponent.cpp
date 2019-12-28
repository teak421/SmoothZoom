// Fill out your copyright notice in the Description page of Project Settings.

#include "SmoothZoomComponent.h"
#include "GameFramework/SpringArmComponent.h"


DEFINE_LOG_CATEGORY(ZoomLog);

// Sets default values for this component's properties
USmoothZoomComponent::USmoothZoomComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// SmoothZoom Defaults -- Change inside of your BP where the actor component is located
	MinTargetLength = 150.0f;
	MaxTargetLength = 1500.0f;
	ZoomUnits = 125.0f;
	ZoomSmoothness = 9.0f;
	bDebug = false;
	CurrentVersion = 2.00f;
}


// Called when the game starts
void USmoothZoomComponent::BeginPlay() { Super::BeginPlay(); }


// Called every frame
void USmoothZoomComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!ensure(SpringArm)) { return; };

	// Only call when need to, saves MS's 
	if (!FMath::IsNearlyEqual(SpringArm->TargetArmLength, DesiredArmLength, 0.5f)) {
		SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, DesiredArmLength, DeltaTime, ZoomSmoothness);
	}
}

void USmoothZoomComponent::SetSpringArmComponent(USpringArmComponent* AssignedSpringArm)
{
	DesiredArmLength = AssignedSpringArm->TargetArmLength;
	SpringArm = AssignedSpringArm;
}

void USmoothZoomComponent::SmoothCameraZoom(bool bZoomOut)
{
	DesiredArmLength = bZoomOut ? SpringArm->TargetArmLength + ZoomUnits
		: SpringArm->TargetArmLength + (ZoomUnits * -1);
	if (DesiredArmLength > MaxTargetLength || DesiredArmLength < MinTargetLength) {
		DesiredArmLength = FMath::Min<float>(FMath::Max<float>(DesiredArmLength, MinTargetLength), MaxTargetLength);
	}

	if (bDebug) { SmoothZoomLog(); }
}

void USmoothZoomComponent::SmoothZoomLog()
{
	UE_LOG(ZoomLog, Log, TEXT("ArmLength: %f, Min: %f Max: %f, ZUnits: %f, Smoothness: %f"),
	DesiredArmLength, MinTargetLength, MaxTargetLength, ZoomUnits, ZoomSmoothness)
}

