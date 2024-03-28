// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InputConfigDataAsset.generated.h"

class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class CITYBUILDER_API UInputConfigDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputMappingContext* DefaultMapping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* MoveInput;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* OrbitInput;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* ZoomInput;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* PitchInput;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* FreeRoamInput;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* EnableFreeRoamInput;

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* PlaceBuildingInput;*/

};
