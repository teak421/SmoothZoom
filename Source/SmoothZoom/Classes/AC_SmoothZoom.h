// 837 Studios - 2016 

#pragma once

#include "Components/ActorComponent.h"
#include "AC_SmoothZoom.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UAC_SmoothZoom : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAC_SmoothZoom();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	UFUNCTION(BlueprintCallable, Category = "Camera|Zoom")
	void SetSpringArmComponent(USpringArmComponent* AssignedSpringArm);
	
	/* TargetArmLength Units that will be subtracted or added*/
	UFUNCTION(BlueprintCallable, Category = "Camera|Zoom")
	void SmoothCameraZoom(float ZoomUnits);

	/* Sets the TargetArmLength to Min*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float MinTargetLength;

	/* Sets the TargetArmLength to Max*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float MaxTargetLength;

	/*How smooth the zoom will be (Higher less smooth, lower more smooth*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	float ZoomSmoothness;

	/* Current Version Number */
	UPROPERTY(VisibleDefaultsOnly, Category = "Camera Zoom")
	float CurrentVersion;

	/* Check this box if you would like to see debug information */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom")
	bool bDebug;

private:

	USpringArmComponent* SpringArm;
	float DesiredArmLength;
};
