// Fill out your copyright notice in the Description page of Project Settings.


#include "CBRoadManager.h"
#include "CityBuilder/Actors/CBRoadTile.h"

ACBRoadManager::ACBRoadManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACBRoadManager::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACBRoadManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACBRoadManager::AddRoadTile(ACBRoadTile* NewRoadTile)
{
	RoadTilesArray.Add(NewRoadTile);
	for (const auto RoadTile : RoadTilesArray)
	{
		RoadTile->OnNewRoadTileAdded();
	}
}
