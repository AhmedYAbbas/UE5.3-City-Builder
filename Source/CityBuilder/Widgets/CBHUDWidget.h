// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CBHUDWidget.generated.h"

class UButton;
class UImage;
class UTextBlock;
class ACBGameModeBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonClickSignature, UButton*, Button);

UCLASS()
class CITYBUILDER_API UCBHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnButtonClicked(UButton* Button);
	UFUNCTION()
	void OnPlaceableBought(int32 NewMoney);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* RoadButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* BuildingButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UImage* HighlightImage;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UTextBlock* MoneyText;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnButtonClickSignature OnButtonClickDelegate;

	UPROPERTY(BlueprintReadOnly)
	bool bHighlight = false;

private:
	UPROPERTY()
	ACBGameModeBase* GameMode;
};
