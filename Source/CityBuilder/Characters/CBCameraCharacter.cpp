// Fill out your copyright notice in the Description page of Project Settings.


#include "CBCameraCharacter.h"
#include "CityBuilder/Controllers/CBPlayerController.h"
#include "CityBuilder/Input/InputConfigDataAsset.h"
#include "CityBuilder/Actors/CBBuilding.h"
#include "CityBuilder/ActorComponents/Clickable.h"
#include "CityBuilder/ActorComponents/Ploppable.h"
#include "Citybuilder/Actors/CBGridManager.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

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

	InitialMovementSpeed = GetCharacterMovement()->MaxWalkSpeed;
	UpdateMovementSpeed();

	SetPlacementMode(true);
}

void ACBCameraCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bPlacementMode)
	{
		UpdatePlacement();
	}
}

void ACBCameraCharacter::Move(const FInputActionValue& Value)
{
	if (Controller)
	{
		const FVector MoveValue = Value.Get<FVector>();
		const FRotator MovementRotation(0.f, GetControlRotation().Yaw, 0.f);
		if (MoveValue.X)
		{
			const FVector Direction = MovementRotation.RotateVector(FVector::ForwardVector);
			AddMovementInput(Direction, MoveValue.X);
		}

		if (MoveValue.Y)
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
		if (OrbitValue)
		{
			AddControllerYawInput(OrbitValue * OrbitSpeed);
		}
	}
}

void ACBCameraCharacter::Pitch(const FInputActionValue& Value)
{
	if (Controller)
	{
		const float PitchValue = Value.Get<float>();
		if (PitchValue)
		{
			FRotator SpringArmRotation = SpringArm->GetComponentRotation();
			SpringArmRotation.Pitch += PitchValue * PitchSpeed;
			SpringArmRotation.Pitch = FMath::ClampAngle(SpringArmRotation.Pitch, MinPitch, MaxPitch);
			SpringArm->SetWorldRotation(SpringArmRotation);
		}
	}
}

void ACBCameraCharacter::Zoom(const FInputActionValue& Value)
{
	if (Controller)
	{
		const float ZoomValue = Value.Get<float>();
		if (ZoomValue)
		{
			const float DesiredArmLength = (ZoomValue * ZoomSpeed) + SpringArm->TargetArmLength;
			const float ClampedArmLength = FMath::Clamp(DesiredArmLength, MinZoom, MaxZoom);
			SpringArm->TargetArmLength = ClampedArmLength;
			UpdateMovementSpeed();
		}
	}
}

void ACBCameraCharacter::FreeRoam(const FInputActionValue& Value)
{
	if (Controller)
	{
		const FVector FreeRoamValue = Value.Get<FVector>();
		if (FreeRoamValue.X)
		{
			Orbit(FreeRoamValue.X);
		}

		if (FreeRoamValue.Y)
		{
			Pitch(FreeRoamValue.Y);
		}
	}
}

void ACBCameraCharacter::UpdateMovementSpeed()
{
	const float ArmLength = SpringArm->TargetArmLength;
	GetCharacterMovement()->MaxWalkSpeed = (ArmLength / MinZoom) * InitialMovementSpeed;
}

void ACBCameraCharacter::SetPlacementMode(bool bEnable)
{
	if (bPlacementMode == bEnable)
	{
		return;
	}
	
	bPlacementMode = bEnable;
	if (bPlacementMode)
	{
		if (UWorld* World = GetWorld())
		{
			PloppableBuilding = World->SpawnActor(BuildingBlueprint);
			if (ACBBuilding* Building = Cast<ACBBuilding>(PloppableBuilding))
			{
				Building->Clickable->DestroyComponent();
			}
		}
	}
	else
	{
		if (PloppableBuilding)
		{
			PloppableBuilding->Destroy();
		}
	}
}

void ACBCameraCharacter::UpdatePlacement()
{
	FVector WorldLocation;
	FVector WorldDirection;
	PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection);

	if (const UWorld* World = GetWorld())
	{
		FHitResult HitResult;
		FVector Start = WorldLocation;
		FVector End = (WorldDirection * 10000.f) + WorldLocation;
		World->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_GameTraceChannel1);
		if (HitResult.bBlockingHit)
		{
			ACBGridManager* GridManager = Cast<ACBGridManager>(UGameplayStatics::GetActorOfClass(this, ACBGridManager::StaticClass()));
			const FVector Location = GridManager->GetClosestGridPosition(HitResult.Location);
			PloppableBuilding->SetActorLocation(Location);
		}
	}
}

void ACBCameraCharacter::SpawnBuilding(const FInputActionValue& Value)
{
	if (bPlacementMode)
	{
		if (ACBBuilding* Building = Cast<ACBBuilding>(PloppableBuilding))
		{
			if (Building->Ploppable && Building->Ploppable->bPlacementValid)
			{
				if (UWorld* World = GetWorld())
				{
					const FTransform& Transform = PloppableBuilding->GetActorTransform();
					AActor* SpawnedBuilding = World->SpawnActor(BuildingBlueprint, &Transform);
					if (ACBBuilding* ConstructedBuilding = Cast<ACBBuilding>(SpawnedBuilding))
					{
						ConstructedBuilding->Ploppable->DestroyComponent();
					}
					//SetPlacementMode(false);
				}
			}
		}
	}
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
					PEI->BindAction(PlayerController->InputData->PitchInput, ETriggerEvent::Triggered, this, &ACBCameraCharacter::Pitch);
					PEI->BindAction(PlayerController->InputData->FreeRoamInput, ETriggerEvent::Triggered, this, &ACBCameraCharacter::FreeRoam);
					PEI->BindAction(PlayerController->InputData->PlaceInput, ETriggerEvent::Triggered, this, &ACBCameraCharacter::SpawnBuilding);
				}
			}
		}
	}
}

