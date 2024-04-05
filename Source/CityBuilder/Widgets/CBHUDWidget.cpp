// Fill out your copyright notice in the Description page of Project Settings.


#include "CBHUDWidget.h"
#include "CityBuilder/GameModes/CBGameModeBase.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/CanvasPanelSlot.h"
#include "Kismet/GameplayStatics.h"

void UCBHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	OnButtonClickDelegate.AddDynamic(this, &UCBHUDWidget::OnButtonClicked);

	RoadButton->bIsVariable = true;
	BuildingButton->bIsVariable = true;
	HighlightImage->SetVisibility(ESlateVisibility::Hidden);

	GameMode = Cast<ACBGameModeBase>(UGameplayStatics::GetGameMode(this));
	GameMode->OnPlaceableBought.AddDynamic(this, &UCBHUDWidget::OnPlaceableBought);
}

void UCBHUDWidget::OnButtonClicked(UButton* Button)
{
	UCanvasPanelSlot* HighlightSlot = Cast<UCanvasPanelSlot>(HighlightImage->Slot);
	UCanvasPanelSlot* ButtonSlot = Cast<UCanvasPanelSlot>(Button->Slot);
	if (HighlightSlot && ButtonSlot)
	{
		bHighlight = HighlightSlot->GetPosition() != ButtonSlot->GetPosition();
		if (bHighlight)
		{
			HighlightSlot->SetPosition(ButtonSlot->GetPosition());
			HighlightImage->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			HighlightImage->SetVisibility(ESlateVisibility::Hidden);
			HighlightSlot->SetPosition(FVector2D(0, 0));
		}
	}
}

void UCBHUDWidget::OnPlaceableBought(int32 NewMoney)
{
	MoneyText->SetText(FText::FromString(FString::FromInt(NewMoney)));
}

