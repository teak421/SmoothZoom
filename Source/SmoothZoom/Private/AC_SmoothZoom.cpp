// Fill out your copyright notice in the Description page of Project Settings.

#include "SmoothZoomPrivatePCH.h"
#include "Classes/AC_SmoothZoom.h"


// Sets default values for this component's properties
UAC_SmoothZoom::UAC_SmoothZoom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAC_SmoothZoom::BeginPlay()
{
	Super::BeginPlay();

	// ...

}
// Called every frame
void UAC_SmoothZoom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	{
		Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
		if (DesiredArmLength > MinTargetLength && DesiredArmLength < MaxTargetLength)
		{
			SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, DesiredArmLength, DeltaTime, ZoomSmoothness);
		}
	}
}
void UAC_SmoothZoom::SetNewSpringArmComponent(USpringArmComponent* NewSpringArm) { SpringArm = NewSpringArm; }

void UAC_SmoothZoom::SmoothCameraZoom(float ZoomUnits)
{
	if (SpringArm)
	{
		DesiredArmLength = SpringArm->TargetArmLength + ZoomUnits;
	}
	if (bDebug)
	{
		UE_LOG(LogTemp, Warning, TEXT("Min Target: %f Max Target: %f DesiredArmLength: %f ZoomUnits: %f"),
			MinTargetLength, MaxTargetLength, DesiredArmLength, ZoomUnits)
	}
}
