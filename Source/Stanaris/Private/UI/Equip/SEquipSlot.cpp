// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Equip/SEquipSlot.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "SBorder.h"

#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEquipSlot::Construct(const FArguments& InArgs)
{
	IndexSlot = InArgs._IndexSlot;

	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.WidthOverride(50)
		.HeightOverride(50)
		[
			SNew(SBorder)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.BorderImage(&EmptySlotStyle->BackgroundBrush)
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
