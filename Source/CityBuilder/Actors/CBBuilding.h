// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CBPlaceableBase.h"
#include "CBBuilding.generated.h"

UCLASS()
class CITYBUILDER_API ACBBuilding : public ACBPlaceableBase
{
	GENERATED_BODY()
	
public:	
	ACBBuilding();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
