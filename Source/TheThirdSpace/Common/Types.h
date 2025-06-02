#pragma once

#include "CoreMinimal.h"



UENUM(BlueprintType)
enum class ECardState : uint8
{
	None = 0		UMETA(DisplayName = "None"),
	In				UMETA(DisplayName = "正在进入"),
	StateIn			UMETA(DisplayName = "在其中"),
	Out				UMETA(DisplayName = "正在退出")
};


UENUM(BlueprintType)
enum class ETouchState : uint8
{
	None = 0		UMETA(DisplayName = "触摸关闭"),
	Normal			UMETA(DisplayName = "普通"),
	Movie			UMETA(DisplayName = "电影模式")
};

UENUM(BlueprintType)
enum class ETransitionPath : uint8
{
	None = 0		UMETA(DisplayName = "没有任何路径"),
	SceneToMovie	UMETA(DisplayName = "场景到电影厅")
};