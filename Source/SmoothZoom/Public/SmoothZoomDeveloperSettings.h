// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "SmoothZoomDeveloperSettings.generated.h"

/**
* Sets the defaults for SmoothZoom Camera Plugin
*/
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Smooth Zoom Camera"))
class SMOOTHZOOM_API USmoothZoomDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	USmoothZoomDeveloperSettings(const FObjectInitializer& ObjectInitializer);

	/* Sets the Minimum Target Arm Length */
	UPROPERTY(config, EditAnywhere, Category = "Smooth Zoom Camera Defaults", meta = (DisplayName = "Minimum Target Lengeth"))
	float MinTargetLength;

	/* Sets the Maximum Target Arm Length*/
	UPROPERTY(config, EditAnywhere, Category = "Smooth Zoom Camera Defaults", meta = (DisplayName = "Maximum Target Lengeth"))
	float MaxTargetLength;

	/* Determines the number of units are added or subtracted from the target arm length*/
	UPROPERTY(config, EditAnywhere, Category = "Smooth Zoom Camera Defaults", meta = (DisplayName = "Zoom Units"))
	float ZoomUnits;

	/*How smooth the zoom will be (Higher less smooth, lower more smooth*/
	UPROPERTY(config, EditAnywhere, Category = "Smooth Zoom Camera Defaults", meta = (DisplayName = "Zoom Smoothness"))
	float ZoomSmoothness;

	/* If checked, will display debug information in the log window*/
	UPROPERTY(config, EditAnywhere, Category = "Smooth Zoom Camera Defaults", meta = (DisplayName = "Debug Log?"))
	bool bDebug;

};