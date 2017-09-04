// Fill out your copyright notice in the Description page of Project Settings.

#include "SmoothZoomDeveloperSettings.h"

USmoothZoomDeveloperSettings::USmoothZoomDeveloperSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	MinTargetLength(150.0f),
	MaxTargetLength(1500.0f),
	ZoomUnits(125.0f),
	ZoomSmoothness(9.0f),
	bDebug(false)

{

}


