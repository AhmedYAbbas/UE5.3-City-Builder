// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CBHUDBase.generated.h"

class UCBHUDWidget;

/**
 * 
 */
UCLASS()
class CITYBUILDER_API ACBHUDBase : public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(BlueprintReadWrite)
	UCBHUDWidget* HUDWidget;
};
