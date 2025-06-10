// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CardMeshComp.generated.h"



USTRUCT(BlueprintType)
struct FCardUpdateParam
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovieCards")
	UStaticMeshComponent* CardMeshComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovieCards")
	UMaterialInstanceDynamic* CurMID = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovieCards")
	float CurTimeOnLine = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovieCards")
	int32 UniqueID = -1;

	//卡片在卡片集中分配的ID，由cards分配，-1为无效值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovieCards")
	int32 CurPosID = -1;

	//为了播放开始动画，给前7个卡片设置的初始化ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovieCards")
	int32 InitialTargetPosID = -1;

	//当前时间映射的可见性参数
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardMesh")
};

/**
 * 
 */
UCLASS()
class THETHIRDSPACE_API AMovieCards : public AActor
{
	GENERATED_BODY()

public:
	
};
