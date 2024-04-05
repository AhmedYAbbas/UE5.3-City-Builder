// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBCitizenManager.generated.h"

class UMaterialInterface;
class UDataTable;

UCLASS()
class CITYBUILDER_API ACBCitizenManager : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBCitizenManager();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<USkeletalMesh*> Citizens;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UMaterialInterface*> GenderMaterials;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* MaleFirstName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* FemaleFirstName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* LastName;
};
