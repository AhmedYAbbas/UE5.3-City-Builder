// Fill out your copyright notice in the Description page of Project Settings.


#include "CBCitizen.h"
#include "CityBuilder/Actors/CBCitizenManager.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"

ACBCitizen::ACBCitizen()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACBCitizen::BeginPlay()
{
	Super::BeginPlay();
	
	CitizenManager = Cast<ACBCitizenManager>(UGameplayStatics::GetActorOfClass(this, ACBCitizenManager::StaticClass()));
	GenerateCitizen();
}

void ACBCitizen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACBCitizen::GenerateCitizen()
{
	AssignRandomSkeletalMesh();
	AssignGender();
	AssignName();
	AssignEducation();
	AssignAge();
}

void ACBCitizen::AssignRandomSkeletalMesh()
{
	if (auto SkeletalMeshComponent = GetMesh())
	{
		switch (FMath::RandRange(0, 2))
		{
			case 0:
				SkeletalMeshComponent->SetSkeletalMesh(CitizenManager->Citizens[0]);
			case 1:
				SkeletalMeshComponent->SetSkeletalMesh(CitizenManager->Citizens[1]);
			case 2:
				SkeletalMeshComponent->SetSkeletalMesh(CitizenManager->Citizens[2]);
			default:
				break;
		}
	}
}

void ACBCitizen::AssignGender()
{
	if (FMath::RandBool())
	{
		Gender = EGender::Female;
		if (auto SkeletalMeshComponent = GetMesh())
		{
			SkeletalMeshComponent->SetMaterial(0, CitizenManager->GenderMaterials[1]);
		}
	}
	else
	{
		Gender = EGender::Male;
		if (auto SkeletalMeshComponent = GetMesh())
		{
			SkeletalMeshComponent->SetMaterial(0, CitizenManager->GenderMaterials[0]);
		}
	}
}

FString ACBCitizen::GetRandomName(UDataTable* NameDataTable)
{
	TArray<FName> RowNames = NameDataTable->GetRowNames();
	int32 RandomIndex = FMath::RandRange(0, RowNames.Num() - 1);
	if (FCitizenName* Row = NameDataTable->FindRow<FCitizenName>(RowNames[RandomIndex], FString()))
	{
		return Row->Name;
	}
	return FString();
}

void ACBCitizen::AssignName()
{
	switch (Gender)
	{
		case EGender::Male:
		{
			FString AppendedName = GetRandomName(CitizenManager->MaleFirstName) + " " + GetRandomName(CitizenManager->LastName);
			Name = AppendedName;
			break;
		}
		case EGender::Female:
		{
			FString AppendedName = GetRandomName(CitizenManager->FemaleFirstName) + " " + GetRandomName(CitizenManager->LastName);
			Name = AppendedName;
			break;
		}
	}
}

void ACBCitizen::AssignEducation()
{
	switch (FMath::RandRange(0, 2))
	{
		case 0:
			EducationLevel = EEducationLevel::Basic;
			break;
		case 1:
			EducationLevel = EEducationLevel::Advanced;
			break;
		case 2:
			EducationLevel = EEducationLevel::Higher;
			break;
		default:
			break;
	}
}

void ACBCitizen::AssignAge()
{
	Age = FMath::RandRange(0, 60);
}


void ACBCitizen::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

