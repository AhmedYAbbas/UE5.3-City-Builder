// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CBPlaceableBase.h"
#include "CBRoadTile.generated.h"

class ACBGridCell;

/**
 * 
 */
UCLASS()
class CITYBUILDER_API ACBRoadTile : public ACBPlaceableBase
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnNewRoadTileAdded();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION(BlueprintCallable)
	void UpdateSideOfRoadTile(ACBGridCell* NeighbouringCell, USceneComponent* Pathway);
};
