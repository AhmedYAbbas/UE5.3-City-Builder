// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "CBGameStateBase.generated.h"

UCLASS()
class CITYBUILDER_API ACBGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	int32 CurrentMoney = 20000;
};
