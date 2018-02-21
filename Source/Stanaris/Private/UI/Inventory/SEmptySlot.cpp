// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/SEmptySlot.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "SBorder.h"
#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEmptySlot::Construct(const FArguments& InArgs)
{
	HUD = InArgs._HUD;
	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	ChildSlot
		[
			// Populate the widget
			SNew(SBox)
			.WidthOverride(50)
			.HeightOverride(50)
			[
				SNew(SBorder)
				.BorderImage(&EmptySlotStyle->BackgroundBrush)
			]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
