// Fill out your copyright notice in the Description page of Project Settings.


#include "CBHUDWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"

void UCBHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	OnButtonClickDelegate.AddDynamic(this, &UCBHUDWidget::OnButtonClicked);

	RoadButton->bIsVariable = true;
	BuildingButton->bIsVariable = true;
	HighlightImage->SetVisibility(ESlateVisibility::Hidden);
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

