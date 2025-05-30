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