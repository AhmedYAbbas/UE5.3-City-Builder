// Fill out your copyright notice in the Description page of Project Settings.


#include "Ploppable.h"
#include "CityBuilder/Actors/CBGridManager.h"
#include "CityBuilder/Actors/CBGridCell.h"
#include "CityBuilder/Actors/CBPlaceableBase.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UPloppable::UPloppable()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UPloppable::BeginPlay()
{
	Super::BeginPlay();
	
	GridManager = Cast<ACBGridManager>(UGameplayStatics::GetActorOfClass(this, ACBGridManager::StaticClass()));
}

void UPloppable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UpdateState();
}

void UPloppable::UpdateState()
{
	if (AActor* Owner = GetOwner())
	{
		if (GridManager)
		{
			if (ACBGridCell* Cell = GridManager->GetClosestGridCell(Owner->GetActorLocation()))
			{
				bPlacementValid = Cell->IsOccupied() ? false : true;
				RoadPlaceableCheck(Cell);
			}
		}

		TArray<UStaticMeshComponent*> StaticMeshComponents;
		Owner->GetComponents(StaticMeshComponents);
		for (const auto StaticMesh : StaticMeshComponents)
		{
			StaticMesh->SetMaterial(0, bPlacementValid ? PloppableMaterial : InvalidPloppableMaterial);
		}
	}
}

void UPloppable::RoadPlaceableCheck(ACBGridCell* InGridCell)
{
	if (ACBPlaceableBase* PlaceableActor = Cast<ACBPlaceableBase>(GetOwner()))
	{
		if (PlaceableActor->GetBuildingType() == EBuildingType::Road)
		{
			DisablePlacementAtJunction(InGridCell, 0, 3); // NW
			DisablePlacementAtJunction(InGridCell, 0, 1); // NE
			DisablePlacementAtJunction(InGridCell, 2, 3); // SW
			DisablePlacementAtJunction(InGridCell, 1, 2); // SE
		}
	}
}

void UPloppable::DisablePlacementAtJunction(ACBGridCell* CenterCell, int FirstCorner, int SecondCorner)
{
	if (CenterCell->Neighbours[FirstCorner] && CenterCell->Neighbours[SecondCorner] &&
		(CenterCell->Neighbours[FirstCorner]->GetOccupyingType() == EBuildingType::Road && CenterCell->Neighbours[SecondCorner]->GetOccupyingType() == EBuildingType::Road))
	{
		if (CenterCell->Neighbours[FirstCorner]->Neighbours[SecondCorner])
		{
			if (CenterCell->Neighbours[FirstCorner]->Neighbours[SecondCorner]->GetOccupyingType() == EBuildingType::Road)
			{
				bPlacementValid = false;
				return;
			}
		}
	}
}
