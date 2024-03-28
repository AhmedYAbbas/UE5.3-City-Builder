// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CBPlayerController.generated.h"

class UInputConfigDataAsset;

/**
 * 
 */
UCLASS()
class CITYBUILDER_API ACBPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputConfigDataAsset* InputData;
};
