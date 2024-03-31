// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Ploppable.generated.h"

class UMaterialInterface;
class ACBGridManager;
class ACBGridCell;

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

public:
	bool bPlacementValid = false;

private:
	UPROPERTY()
	ACBGridManager* GridManager;

	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* PloppableMaterial;
	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* InvalidPloppableMaterial;
};
