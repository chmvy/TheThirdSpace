#pragma once

#include "CoreMinimal.h"


//卡片的状态，正在播放进入动画，在其中，正在退出
UENUM(BlueprintType)
enum class ECardState : uint8
{
	None = 0		UMETA(DisplayName = "None"),
	In				UMETA(DisplayName = "正在进入"),
	StateIn			UMETA(DisplayName = "在其中"),
	Out				UMETA(DisplayName = "正在退出")
};

//路径集
UENUM(BlueprintType)
enum class ETransitionPath : uint8
{
	None = 0		UMETA(DisplayName = "没有任何路径"),
	SceneToMovie	UMETA(DisplayName = "场景到电影厅")
};

//房间枚举
UENUM(BlueprintType)
enum class ESubRoom : uint8
{
	OutSide = 0,
	Cinema
};