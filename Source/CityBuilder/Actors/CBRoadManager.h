// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBRoadManager.generated.h"

class ACBRoadTile;

UCLASS()
class CITYBUILDER_API ACBRoadManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBRoadManager();
	virtual void Tick(float DeltaTime) override;
	void AddRoadTile(ACBRoadTile* NewRoadTile);

protected:
	virtual void BeginPlay() override;

private:
	TArray<ACBRoadTile*> RoadTilesArray;
};
