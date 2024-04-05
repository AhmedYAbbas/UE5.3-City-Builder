// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CityBuilder/CityBuilder.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBPlaceableBase.generated.h"

class ACBGridCell;
class UClickable;
class UPloppable;

UCLASS(Abstract)
class CITYBUILDER_API ACBPlaceableBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBPlaceableBase();
	virtual void Tick(float DeltaTime) override;

	void SetGridCellRef(ACBGridCell* Cell) { GridCellRef = Cell; }

	ACBGridCell* GetGridCellRef() const { return GridCellRef; }
	EBuildingType GetBuildingType() const { return BuildingType; }

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UClickable* Clickable;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UPloppable* Ploppable;
	UPROPERTY(EditDefaultsOnly)
	int32 Cost = 0;

protected:
	UPROPERTY(BlueprintReadOnly)
	ACBGridCell* GridCellRef;
	UPROPERTY(EditDefaultsOnly)
	EBuildingType BuildingType = EBuildingType::None;
};
