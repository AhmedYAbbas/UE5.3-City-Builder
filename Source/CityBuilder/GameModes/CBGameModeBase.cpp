// Fill out your copyright notice in the Description page of Project Settings.


#include "CBGameModeBase.h"
#include "CityBuilder/GameStates/CBGameStateBase.h"

void ACBGameModeBase::BeginPlay()
{
	CBGameState = GetGameState<ACBGameStateBase>();
}

bool ACBGameModeBase::CanAffordPlaceable(int32 PlaceableCost)
{
	if (CBGameState)
	{
		return PlaceableCost <= CBGameState->CurrentMoney;
	}
	return false;
}

void ACBGameModeBase::BuyPlaceable(int32 PlaceableCost)
{
	if (CanAffordPlaceable(PlaceableCost))
	{
		CBGameState->CurrentMoney -= PlaceableCost;
		OnPlaceableBought.Broadcast(CBGameState->CurrentMoney);
	}
}

