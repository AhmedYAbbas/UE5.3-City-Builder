// Fill out your copyright notice in the Description page of Project Settings.


#include "CBGridCell.h"

ACBGridCell::ACBGridCell()
{
	PrimaryActorTick.bCanEverTick = true;

	Neighbours.SetNum(4);
}

void ACBGridCell::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACBGridCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACBGridCell::SetOccupied(EBuildingType BuildingType, AActor* Occupying)
{
	bOccupied = true;
	OccupyingType = BuildingType;
	OccupyingActor = Occupying;

	for (auto Cell : Neighbours)
	{
		if (Cell)
		{
			Cell->DebugShowOccupiedNeighbours();
		}
	}
}
