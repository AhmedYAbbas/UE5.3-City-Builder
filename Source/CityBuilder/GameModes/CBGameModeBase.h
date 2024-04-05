// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CBGameModeBase.generated.h"

class ACBGameStateBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPlaceableBoughtSignature, int32, NewMoney);

UCLASS()
class CITYBUILDER_API ACBGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	bool CanAffordPlaceable(int32 PlaceableCost);
	void BuyPlaceable(int32 PlaceableCost);

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FPlaceableBoughtSignature OnPlaceableBought;

private:
	UPROPERTY()
	ACBGameStateBase* CBGameState;

};
