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

struct FInputActionValue;

UCLASS()
class CITYBUILDER_API ACBCameraCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACBCameraCharacter();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

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

	void UpdateMovementSpeed();
	void SetPlacementMode(bool bEnable);
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY()
	AActor* PloppableBuilding = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = "Buildings")
	TSubclassOf<ACBBuilding> BuildingBlueprint;

	bool bPlacementMode = false;
};
