// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Clickable.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CITYBUILDER_API UClickable : public UActorComponent
{
	GENERATED_BODY()

public:	
	UClickable();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnMouseClicked(AActor* TouchedActor, FKey ButtonPressed);
	UFUNCTION()
	void OnMouseHover(AActor* TouchedActor);
	UFUNCTION()
	void OnMouseHoverEnd(AActor* TouchedActor);

private:
	UPROPERTY()
	UStaticMeshComponent* StaticMeshRef;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* ClickedMaterial;
	UPROPERTY(EditAnywhere)
	UMaterialInterface* UnclickedMaterial;

	bool bClicked = false;
};
