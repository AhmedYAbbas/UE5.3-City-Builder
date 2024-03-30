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
	PopulateGridCellNeighbours();
}

void ACBGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ACBGridCell* ACBGridManager::GetClosestGridCell(const FVector& InPos)
{
	float ClosestDistance = FVector::DistSquared(InPos, GridArray[0]->GetActorLocation());
	int32 CellIndex = 0;
	for (int32 i = 0; i < GridArray.Num(); i++)
	{
		const FVector CellLocation = GridArray[i]->GetActorLocation();
		const float Distance = FVector::DistSquared(InPos, CellLocation);
		if (Distance < ClosestDistance)
		{
			ClosestDistance = Distance;
			CellIndex = i;
		}
	}
	return GridArray[CellIndex];
}

void ACBGridManager::PopulateGrid()
{
	if (!GridArray.IsEmpty())
	{
		GridArray.Empty();
	}

	float WorldOffset = (0.5f * GridSize * CellSize) - (0.5f * CellSize);
	for (int32 Y = 0; Y < GridSize; Y++)
	{
		for (int32 X = 0; X < GridSize; X++)
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

void ACBGridManager::PopulateGridCellNeighbours()
{
	for (int32 i = 0; i < GridArray.Num(); i++)
	{
		// North = 0
		if (i + GridSize < GridArray.Num())
		{
			GridArray[i]->Neighbours[0] = GridArray[i + GridSize];
		}

		// East = 1
		if ((i + 1) % GridSize != 0)
		{
			GridArray[i]->Neighbours[1] = GridArray[i + 1];
		}

		// South = 2
		if (i - GridSize >= 0)
		{
			GridArray[i]->Neighbours[2] = GridArray[i - GridSize];
		}

		// West = 3
		if (i % GridSize != 0)
		{
			GridArray[i]->Neighbours[3] = GridArray[i - 1];
		}
	}
}
