// Fill out your copyright notice in the Description page of Project Settings.


#include "CBPlaceableBase.h"
#include "CityBuilder/ActorComponents/Clickable.h"
#include "CityBuilder/ActorComponents/Ploppable.h"

ACBPlaceableBase::ACBPlaceableBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Clickable = CreateDefaultSubobject<UClickable>(TEXT("Clickable"));
	Ploppable = CreateDefaultSubobject<UPloppable>(TEXT("Ploppable"));
	AddInstanceComponent(Clickable);
	AddInstanceComponent(Ploppable);
}

void ACBPlaceableBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACBPlaceableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

