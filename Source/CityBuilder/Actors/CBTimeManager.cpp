// Fill out your copyright notice in the Description page of Project Settings.


#include "CBTimeManager.h"

ACBTimeManager::ACBTimeManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACBTimeManager::BeginPlay()
{
	Super::BeginPlay();
}

void ACBTimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (TimeMode)
	{
		case ETimeDilation::Normal:
			UpdateCurrentTimeOfDay(NormalSpeed, DeltaTime);
			break;
		case ETimeDilation::Fast:
			UpdateCurrentTimeOfDay(FastSpeed, DeltaTime);
			break;
		case ETimeDilation::Fastest:
			UpdateCurrentTimeOfDay(FastestSpeed, DeltaTime);
			break;
	}
}

void ACBTimeManager::UpdateCurrentTimeOfDay(float SpeedModifier, float DeltaTime)
{
	CurrentTimeOfDay += SpeedModifier * DeltaTime;
	if (CurrentTimeOfDay >= 24.f)
	{
		CurrentTimeOfDay -= 24.f;
	}
}
