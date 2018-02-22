// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/SEmptySlot.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "SBorder.h"
#include "SOverlay.h"
#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEmptySlot::Construct(const FArguments& InArgs)
{
	HUD = InArgs._HUD;
	IndexSlot = InArgs._IndexSlot;
	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(SBox)
			.WidthOverride(100)
			.HeightOverride(100)
			[
				SNew(SBorder)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.BorderImage(&EmptySlotStyle->BackgroundBrush)
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
