// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EBuildingType
{
	None UMETA(DisplayName = "None"),
	Zoned UMETA(DisplayName = "Zoned"),
	Placed UMETA(DisplayName = "Placed"),
	Road UMETA(DisplayName = "Road"),
	BuildingType_Max UMETA(Hidden)
};