// Fill out your copyright notice in the Description page of Project Settings.


#include "Clickable.h"

#include "Components/StaticMeshComponent.h"

UClickable::UClickable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UClickable::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		Owner->OnClicked.AddDynamic(this, &UClickable::OnMouseClicked);
		Owner->OnBeginCursorOver.AddDynamic(this, &UClickable::OnMouseHover);
		Owner->OnEndCursorOver.AddDynamic(this, &UClickable::OnMouseHoverEnd);

		if (UStaticMeshComponent* StaticMesh = Owner->GetComponentByClass<UStaticMeshComponent>())
		{
			StaticMeshRef = StaticMesh;
		}
	}
}

void UClickable::OnMouseClicked(AActor* TouchedActor, FKey ButtonPressed)
{
	bClicked = !bClicked;
	if (StaticMeshRef)
	{
		StaticMeshRef->SetMaterial(0, bClicked ? ClickedMaterial : UnclickedMaterial);
	}
}

void UClickable::OnMouseHover(AActor* TouchedActor)
{
	if (StaticMeshRef)
	{
		StaticMeshRef->SetRenderCustomDepth(true);
	}
}

void UClickable::OnMouseHoverEnd(AActor* TouchedActor)
{
	if (StaticMeshRef)
	{
		StaticMeshRef->SetRenderCustomDepth(false);
	}
}

void UClickable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

