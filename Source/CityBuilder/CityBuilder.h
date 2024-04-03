// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EBuildingType : uint8
{
	None UMETA(DisplayName = "None"),
	Zoned UMETA(DisplayName = "Zoned"),
	Placed UMETA(DisplayName = "Placed"),
	Road UMETA(DisplayName = "Road"),
	BuildingType_Max UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ETimeDilation : uint8
{
	Normal UMETA(DisplayName = "Normal"),
	Fast UMETA(DisplayName = "Fast"),
	Fastest UMETA(DisplayName = "Fastest"),
	TimeDilation_Max UMETA(Hidden)
};