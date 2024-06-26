// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Ploppable.generated.h"

class UMaterialInterface;
class ACBGridManager;
class ACBGridCell;
class ACBPlaceableBase;
class ACBGameModeBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CITYBUILDER_API UPloppable : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPloppable();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	void UpdateState();
	void RoadPlaceableCheck(ACBGridCell* InGridCell);
	void DisablePlacementAtJunction(ACBGridCell* CenterCell, int FirstCorner, int SecondCorner);
	void CheckCost();

public:
	bool bPlacementValid = false;

private:
	UPROPERTY()
	ACBGridManager* GridManager;
	UPROPERTY()
	ACBPlaceableBase* PlaceableOwner;
	UPROPERTY()
	ACBGameModeBase* CBGameMode;

	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* PloppableMaterial;
	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* InvalidPloppableMaterial;
};
