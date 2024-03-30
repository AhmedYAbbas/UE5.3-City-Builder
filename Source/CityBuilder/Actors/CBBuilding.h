// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBBuilding.generated.h"

class UClickable;
class UPloppable;
class UMaterialInterface;

UCLASS()
class CITYBUILDER_API ACBBuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBBuilding();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UClickable* Clickable;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UPloppable* Ploppable;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMesh;
};
