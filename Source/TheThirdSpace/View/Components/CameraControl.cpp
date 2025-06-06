


#include "CameraControl.h"

#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UCameraControl::UCameraControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCameraControl::InitCameraParam(USpringArmComponent* InSpringArmComp)
{
	if ( IsValid(InSpringArmComp) )
	{
		SpringArm = InSpringArmComp;
		
		CurrentRotationPitch = SpringArm->GetRelativeRotation().Pitch;

		//这个值只会在-180到180之间
		CurrentRotationYaw = SpringArm->GetRelativeRotation().Yaw;
		
		LastRotationPitch = CurrentRotationPitch;
		LastRotationYaw = CurrentRotationYaw;

		
		LastLength = SpringArm->TargetArmLength;
	}
}


// Called when the game starts
void UCameraControl::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UCameraControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UCameraControl::OneFingerRotate(FVector2D InBeginLocation, FVector2D InCurrentLocation)
{
	float MoveX = InCurrentLocation.X - InBeginLocation.X;
	float MoveY = InCurrentLocation.Y - InBeginLocation.Y;

	MoveX *= RotationYZRatio;
	//这里是负值 默认视角pitch值为0
	MoveY *= -RotationYZRatio / 3;

	//这里set的角度有两种可能，如果是正数区间开始，那么就正常叠加就行了，如果是负数区间
	CurrentRotationYaw = FMath::Fmod(MoveX + LastRotationYaw, 360);
	//需要把 CurrentRotationPitch 限制在 -30 到 10 之间
	CurrentRotationPitch =  FMath::Clamp(FMath::Fmod(MoveY + LastRotationPitch, 360),-10.f,15.f);


	if (SpringArm)
	{

		
		SpringArm->SetRelativeRotation(FRotator(CurrentRotationPitch,CurrentRotationYaw,0));

		UE_LOG(LogTemp,Warning,TEXT("CurrentYaw:: %f, GetYaw :: %f"),CurrentRotationYaw,SpringArm->GetRelativeRotation().Yaw)

		if (UKismetMathLibrary::InRange_FloatFloat(SpringArm->GetRelativeRotation().Yaw, 80, 150))
		{
			if (OnRangeIn.IsBound() && CurRangeIndex != 1)
			{
				OnRangeIn.Broadcast(1);
				CurRangeIndex = 1;
			}
		}
		else if (UKismetMathLibrary::InRange_FloatFloat(SpringArm->GetRelativeRotation().Yaw, -140, -20))
		{
			if (OnRangeIn.IsBound() && CurRangeIndex != 0)
			{
				OnRangeIn.Broadcast(0);
				CurRangeIndex = 0;
			}
		}
	}
}

void UCameraControl::TwoFingerScale(float InBeginDis, float InCurrentDis)
{
	float ChangeLength = InCurrentDis - InBeginDis;

	ChangeLength *= -ScaleRatio;

	
	if (SpringArm)
	{
		//限制目标臂长度 100,2000
		SpringArm->TargetArmLength = FMath::Clamp(LastLength + ChangeLength, 100.f, 2000.f);
	}
}

void UCameraControl::FiveFingerTransition()
{
	
}


