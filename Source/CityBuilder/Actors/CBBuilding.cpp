// Fill out your copyright notice in the Description page of Project Settings.

#include "CBBuilding.h"

ACBBuilding::ACBBuilding()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACBBuilding::BeginPlay()
{
	Super::BeginPlay();

	BuildingType = EBuildingType::Placed;
}

void ACBBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
