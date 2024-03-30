// Fill out your copyright notice in the Description page of Project Settings.


#include "CBGridManager.h"
#include "CityBuilder/Actors/CBGridCell.h"

ACBGridManager::ACBGridManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACBGridManager::BeginPlay()
{
	Super::BeginPlay();
	
	PopulateGrid();
}

void ACBGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ACBGridManager::GetClosestGridPosition(const FVector& InPos)
{
	FVector ClosestPosition = GridArray[0]->GetActorLocation();
	float ClosestDistance = FVector::DistSquared(InPos, ClosestPosition);

	for (const auto Cell : GridArray)
	{
		const FVector CellLocation = Cell->GetActorLocation();
		const float Distance = FVector::DistSquared(InPos, CellLocation);
		if (Distance < ClosestDistance)
		{
			ClosestPosition = CellLocation;
			ClosestDistance = Distance;
		}
	}
	return ClosestPosition;
}

void ACBGridManager::PopulateGrid()
{
	if (!GridArray.IsEmpty())
	{
		GridArray.Empty();
	}

	float WorldOffset = (0.5f * GridSize * CellSize) - (0.5f * CellSize);
	for (int Y = 0; Y < GridSize; Y++)
	{
		for (int X = 0; X < GridSize; X++)
		{
			float XPos = (X * CellSize) - WorldOffset;
			float YPos = (Y * CellSize) - WorldOffset;
			FVector CellLocation(XPos, YPos, 0.f);

			if (UWorld* World = GetWorld())
			{
				ACBGridCell* Cell = Cast<ACBGridCell>(World->SpawnActor(GridCell, &CellLocation));
				GridArray.Add(Cell);
			}
		}
	}
}
