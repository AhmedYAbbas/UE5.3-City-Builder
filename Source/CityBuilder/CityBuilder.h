// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CityBuilder.generated.h"

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

UENUM(BlueprintType)
enum class EHealthStauts : uint8
{
	Normal UMETA(DisplayName = "Normal"),
	Sick UMETA(DisplayName = "Sick"),
	Dying UMETA(DisplayName = "Dying"),
	HealthStauts_Max UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ERelationshipStauts : uint8
{
	Single UMETA(DisplayName = "Single"),
	Partnered UMETA(DisplayName = "Partnered"),
	Widowed UMETA(DisplayName = "Widowed"),
	RelationshipStatus_Max UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EGender : uint8
{
	Male UMETA(DisplayName = "Male"),
	Female UMETA(DisplayName = "Female"),
	Gender_Max UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EEducationLevel : uint8
{
	Basic UMETA(DisplayName = "Basic"),
	Advanced UMETA(DisplayName = "Advanced"),
	Higher UMETA(DisplayName = "Higher"),
	Education_Max UMETA(Hidden)
};

USTRUCT()
struct FCitizenName : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString Name;
};