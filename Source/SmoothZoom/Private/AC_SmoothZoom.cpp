// 837 Studios - 2016 

#include "SmoothZoomPrivatePCH.h"
#include "Classes/AC_SmoothZoom.h"

// Sets default values for this component's properties
UAC_SmoothZoom::UAC_SmoothZoom()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CurrentVersion = 0.92f;
}

// Called when the game starts
void UAC_SmoothZoom::BeginPlay() { 	Super::BeginPlay(); }

// Called every frame
void UAC_SmoothZoom::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	{
		Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
		if (DesiredArmLength >= MinTargetLength && DesiredArmLength <= MaxTargetLength)
		{
			SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, DesiredArmLength, DeltaTime, ZoomSmoothness);
		}
	}
}
void UAC_SmoothZoom::SetSpringArmComponent(USpringArmComponent* AssignedSpringArm) { SpringArm = AssignedSpringArm; }

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
		UE_LOG(LogTemp, Warning, TEXT("Min: %f Max: %f Desired: %f Actual: %f ZoomUnits: %f"),
			MinTargetLength, MaxTargetLength, DesiredArmLength, SpringArm->TargetArmLength, ZoomUnits)
	}
}
