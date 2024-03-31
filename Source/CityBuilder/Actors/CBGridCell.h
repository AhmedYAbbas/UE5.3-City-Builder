// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CityBuilder/CityBuilder.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBGridCell.generated.h"

class DebugMaterial;

UCLASS()
class CITYBUILDER_API ACBGridCell : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBGridCell();
	virtual void Tick(float DeltaTime) override;

	void SetOccupied(EBuildingType BuildingType, AActor* Occupying);
	bool IsOccupied() const { return bOccupied; }
	EBuildingType GetOccupyingType() const { return OccupyingType; }

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void DebugShowOccupiedNeighbours();

public:
	UPROPERTY(BlueprintReadOnly)
	TArray<ACBGridCell*> Neighbours;

private:
	UPROPERTY()
	AActor* OccupyingActor;

	bool bOccupied = false;
	EBuildingType OccupyingType;
};

