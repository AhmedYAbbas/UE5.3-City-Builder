// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CityBuilder/CityBuilder.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBTimeManager.generated.h"

UCLASS()
class CITYBUILDER_API ACBTimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBTimeManager();
	virtual void Tick(float DeltaTime) override;

	void SetTimeDilationMode(ETimeDilation TimeDilationMode) { TimeMode = TimeDilationMode; }

protected:
	virtual void BeginPlay() override;

private:
	void UpdateCurrentTimeOfDay(float SpeedModifier, float DeltaTime);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentTimeOfDay;
	UPROPERTY(EditAnywhere)
	float NormalSpeed = 1.f;
	UPROPERTY(EditAnywhere)
	float FastSpeed = 2.f;
	UPROPERTY(EditAnywhere)
	float FastestSpeed = 4.f;

	ETimeDilation TimeMode;
};
