// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "TheThirdSpace/Common/Types.h"
#include "TransitionPathSplineComp.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THETHIRDSPACE_API UTransitionPathSplineComp : public USplineComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTransitionPathSplineComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ETransitionPath TransitionPath;

};
