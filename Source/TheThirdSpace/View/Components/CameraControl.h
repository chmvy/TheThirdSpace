#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraControl.generated.h"


class USpringArmComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THETHIRDSPACE_API UCameraControl : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCameraControl();

	//初始化需要控制的参数 
	UFUNCTION(BlueprintCallable)
	void InitCameraParam(USpringArmComponent* InSpringArmComp);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	

	UFUNCTION(BlueprintCallable, Category="Camera")
	void OneFingerRotate(FVector2D InBeginLocation,FVector2D InCurrentLocation);

	//缩放的时候是否正常计算旋转
	UFUNCTION(blueprintCallable, Category="Camera")
	void TwoFingerScale(float InBeginDis,float InCurrentDis);

	UFUNCTION(BlueprintCallable, Category="Camera")
	void FiveFingerTransition();

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Camera")
	float RotationYZRatio;

	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Camera")
	float ScaleRatio;

private:
	UPROPERTY()
	USpringArmComponent* SpringArm;

	//视角旋转
	float LastRotationYaw;
	float LastRotationPitch;
	float CurrentRotationYaw;
	float CurrentRotationPitch;


	//视角缩放 记录缩放之前的上一个缩放值
	float LastLength;
	
};
