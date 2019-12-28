// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SmoothZoomComponent.generated.h"

class USpringArmComponent;

DECLARE_LOG_CATEGORY_EXTERN(ZoomLog, Log, All);

UCLASS( ClassGroup=(Camera), meta=(BlueprintSpawnableComponent) )
class SMOOTHZOOM_API USmoothZoomComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USmoothZoomComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Camera|Zoom")
	void SetSpringArmComponent(UPARAM(ref)USpringArmComponent* AssignedSpringArm);

	/* TargetArmLength Units that will be subtracted or added*/
	UFUNCTION(BlueprintCallable, Category = "Camera|Zoom")
	void SmoothCameraZoom(bool bZoomOut);

	/* Sets the Minimum Target Arm Length */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float MinTargetLength;

	/* Sets the Maximum Target Arm Length*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float MaxTargetLength;

	/* Determines the number of units are added or subtracted from the target arm length*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float ZoomUnits;

	/*How smooth the zoom will be (Higher less smooth, lower more smooth*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float ZoomSmoothness;

	/* If checked, will display debug information in the log window*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	bool bDebug;

	/* Current Version Number */
	UPROPERTY(VisibleDefaultsOnly, Category = "Camera Zoom")
	float CurrentVersion;

private:

	void SmoothZoomLog();
	float DesiredArmLength;
	class USpringArmComponent* SpringArm;
		
};
