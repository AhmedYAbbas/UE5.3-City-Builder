// Fill out your copyright notice in the Description page of Project Settings.


#include "Ploppable.h"

// Sets default values for this component's properties
UPloppable::UPloppable()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UPloppable::BeginPlay()
{
	Super::BeginPlay();
	
	if (AActor* Owner = GetOwner())
	{
		Owner->OnActorBeginOverlap.AddDynamic(this, &UPloppable::OnOverlapStateChanged);
		Owner->OnActorEndOverlap.AddDynamic(this, &UPloppable::OnOverlapStateChanged);
		UpdateState();
	}
}

void UPloppable::OnOverlapStateChanged(AActor* OverlappedActor, AActor* OtherActor)
{
	UpdateState();
}

void UPloppable::UpdateState()
{
	if (AActor* Owner = GetOwner())
	{
		TSet<AActor*> OverlappingActors;
		Owner->GetOverlappingActors(OverlappingActors);
		bPlacementValid = OverlappingActors.IsEmpty() ? true : false;

		TArray<UStaticMeshComponent*> StaticMeshComponents;
		Owner->GetComponents(StaticMeshComponents);
		for (const auto StaticMesh : StaticMeshComponents)
		{
			StaticMesh->SetMaterial(0, bPlacementValid ? PloppableMaterial : InvalidPloppableMaterial);
		}
	}
}


void UPloppable::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

