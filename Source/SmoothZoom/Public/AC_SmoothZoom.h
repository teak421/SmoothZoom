// 837 Studios - 2016 - Michael Gaskin (teak421) -- MIT License

#pragma once

#include "Components/ActorComponent.h"
#include "InputCoreTypes.h"
#include "AC_SmoothZoom.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(ZoomLog, Log, All);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, Tooltip = "Smooth Zoom Actor Component") )
class SMOOTHZOOM_API UAC_SmoothZoom : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this component's properties
	UAC_SmoothZoom();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Camera|Zoom")
	void SetSpringArmComponent(USpringArmComponent* AssignedSpringArm);

	/* TargetArmLength Units that will be subtracted or added*/
	UFUNCTION(BlueprintCallable, Category = "Camera|Zoom")
	void SmoothCameraZoom(bool bZoomOut);

	/* Sets the TargetArmLength to Min*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float MinTargetLength;

	/* Sets the TargetArmLength to Max*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float MaxTargetLength;

	/* Determines the number of units are added or subtracted from the target arm length*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float ZoomUnits;

	/*How smooth the zoom will be (Higher less smooth, lower more smooth*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float ZoomSmoothness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	bool bDebug;

	/* Current Version Number */
	UPROPERTY(VisibleDefaultsOnly, Category = "Camera Zoom")
	float CurrentVersion;

private:

	void SmoothZoomLog();
	float DesiredArmLength;
	USpringArmComponent* SpringArm;
};
