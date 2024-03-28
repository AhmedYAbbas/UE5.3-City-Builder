// Fill out your copyright notice in the Description page of Project Settings.


#include "CBCameraCharacter.h"
#include "CityBuilder/Controllers/CBPlayerController.h"
#include "CityBuilder/Input/InputConfigDataAsset.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACBCameraCharacter::ACBCameraCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ACBCameraCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACBCameraCharacter::Move(const FInputActionValue& Value)
{
	if (Controller)
	{
		const FVector MoveValue = Value.Get<FVector>();
		FRotator MovementRotation(0.f, GetControlRotation().Yaw, 0.f);
		if (MoveValue.X != 0.f)
		{
			const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);
			AddMovementInput(Direction, MoveValue.X);
		}

		if (MoveValue.Y != 0.f)
		{
			const FVector Direction = MovementRotation.RotateVector(FVector::RightVector);
			AddMovementInput(Direction, MoveValue.Y);
		}
	}
}

void ACBCameraCharacter::Orbit(const FInputActionValue& Value)
{
	if (Controller)
	{
		const float OrbitValue = Value.Get<float>();
		if (OrbitValue != 0.f)
		{
			AddControllerYawInput(OrbitValue * OrbitSpeed);
		}
	}
}

void ACBCameraCharacter::Zoom(const FInputActionValue& Value)
{
	if (Controller)
	{
		const float ZoomValue = Value.Get<float>();
		if (ZoomValue != 0.f)
		{
			float ModifiedArmLength = (ZoomValue * ZoomSpeed) + SpringArm->TargetArmLength;
			float ClampedArmLength = FMath::Clamp(ModifiedArmLength, MinZoom, MaxZoom);
			SpringArm->TargetArmLength = ClampedArmLength;
		}
	}
}

void ACBCameraCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACBCameraCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerController = Cast<ACBPlayerController>(GetController());
	if (const APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (PlayerController)
			{
				Subsystem->ClearAllMappings();
				Subsystem->AddMappingContext(PlayerController->InputData->DefaultMapping, 0);

				if (UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent))
				{
					PEI->BindAction(PlayerController->InputData->MoveInput, ETriggerEvent::Triggered, this, &ACBCameraCharacter::Move);
					PEI->BindAction(PlayerController->InputData->OrbitInput, ETriggerEvent::Triggered, this, &ACBCameraCharacter::Orbit);
					PEI->BindAction(PlayerController->InputData->ZoomInput, ETriggerEvent::Triggered, this, &ACBCameraCharacter::Zoom);
				}
			}
		}
	}
}

