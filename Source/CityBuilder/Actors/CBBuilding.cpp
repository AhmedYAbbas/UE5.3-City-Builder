// Fill out your copyright notice in the Description page of Project Settings.

#include "CBBuilding.h"
#include "CityBuilder/ActorComponents/Clickable.h"
#include "CityBuilder/ActorComponents/Ploppable.h"

ACBBuilding::ACBBuilding()
{
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	Clickable = CreateDefaultSubobject<UClickable>(TEXT("Clickable"));
	Ploppable = CreateDefaultSubobject<UPloppable>(TEXT("Ploppable"));
	AddInstanceComponent(Clickable);
	AddInstanceComponent(Ploppable);
}

void ACBBuilding::BeginPlay()
{
	Super::BeginPlay();
}

void ACBBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
