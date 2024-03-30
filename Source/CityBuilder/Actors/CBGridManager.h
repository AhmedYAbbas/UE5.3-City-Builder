// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBGridManager.generated.h"

class ACBGridCell;

UCLASS()
class CITYBUILDER_API ACBGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBGridManager();
	virtual void Tick(float DeltaTime) override;

	FVector GetClosestGridPosition(const FVector& InPos);

protected:
	virtual void BeginPlay() override;

private:
	void PopulateGrid();

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<ACBGridCell*> GridArray;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ACBGridCell> GridCell;

	UPROPERTY(EditAnywhere)
	int32 GridSize = 10;
	UPROPERTY(EditAnywhere)
	int32 CellSize = 1000;
};
