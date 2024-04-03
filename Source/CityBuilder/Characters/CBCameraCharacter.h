// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CBCameraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ACBPlayerController;
class ACBBuilding;
class ACBGridManager;
class ACBPlaceableBase;
class ACBRoadManager;
class ACBTimeManager;

struct FInputActionValue;

UCLASS()
class CITYBUILDER_API ACBCameraCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACBCameraCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void OnPlacementInfoUpdated(TSubclassOf<ACBPlaceableBase> PlaceableActorType, EBuildingType InPlaceableMode);

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void Orbit(const FInputActionValue& Value);
	UFUNCTION()
	void Pitch(const FInputActionValue& Value);
	UFUNCTION()
	void Zoom(const FInputActionValue& Value);
	UFUNCTION()
	void FreeRoam(const FInputActionValue& Value);
	UFUNCTION()
	void SpawnBuilding(const FInputActionValue& Value);
	UFUNCTION()
	void SetNormalTimeMode(const FInputActionValue& Value);
	UFUNCTION()
	void SetFastTimeMode(const FInputActionValue& Value);
	UFUNCTION()
	void SetFastestTimeMode(const FInputActionValue& Value);

	void UpdateMovementSpeed();
	void SetPlacementMode(bool bEnable);
	void RefreshPlaceableActor();
	void UpdatePlacement();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float OrbitSpeed = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float InitialMovementSpeed = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float ZoomSpeed = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MinZoom = 300.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxZoom = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float PitchSpeed = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MinPitch = 310.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MaxPitch = 350.0f;

private:
	UPROPERTY()
	ACBPlayerController* PlayerController = nullptr;
	UPROPERTY()
	ACBGridManager* GridManager = nullptr;
	UPROPERTY()
	ACBRoadManager* RoadManager = nullptr;
	UPROPERTY()
	ACBTimeManager* TimeManager = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY()
	ACBPlaceableBase* PlaceableActor = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Placeables")
	TSubclassOf<ACBPlaceableBase> PlaceableActorBlueprint;

	bool bPlacementMode = false;
	EBuildingType PlaceableBuildingType;
};
