// Fill out your copyright notice in the Description page of Project Settings.


#include "CBRoadTile.h"
#include "CityBuilder/Actors/CBGridCell.h"

void ACBRoadTile::BeginPlay()
{
	Super::BeginPlay();

	BuildingType = EBuildingType::Road;
}

void ACBRoadTile::UpdateSideOfRoadTile(ACBGridCell* NeighbouringCell, USceneComponent* Pathway)
{
	if (NeighbouringCell)
	{
		NeighbouringCell->GetOccupyingType() == EBuildingType::Road ? Pathway->SetVisibility(false) : Pathway->SetVisibility(true);
	}
}

void ACBRoadTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

