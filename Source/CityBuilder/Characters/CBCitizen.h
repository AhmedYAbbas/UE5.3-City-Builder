// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CityBuilder/CityBuilder.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CBCitizen.generated.h"

class ACBCitizenManager;
class UDataTable;

UCLASS()
class CITYBUILDER_API ACBCitizen : public ACharacter
{
	GENERATED_BODY()

public:
	ACBCitizen();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	void GenerateCitizen();
	void AssignRandomSkeletalMesh();
	void AssignGender();
	FString GetRandomName(UDataTable* NameDataTable);
	void AssignName();
	void AssignEducation();
	void AssignAge();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	FString Name;							  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	int32 Age;								  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	int32 Wealth;							  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	EGender Gender;							  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	ERelationshipStauts RelationshipStatus;	  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	EHealthStauts HealthStauts;				  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	EEducationLevel EducationLevel;			  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	ACBCitizen* Partner;					  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	TArray<ACBCitizen*> Kids;				  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	AActor* Workplace;						  
	UPROPERTY(EditAnywhere, BlueprintReadOnly ,Category = "Info")
	FString OccupationTitle;

private:
	UPROPERTY()
	ACBCitizenManager* CitizenManager;
};
