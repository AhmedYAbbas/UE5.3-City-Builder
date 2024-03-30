// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBGridCell.generated.h"

UCLASS()
class CITYBUILDER_API ACBGridCell : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBGridCell();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
};
