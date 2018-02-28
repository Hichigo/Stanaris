// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/SInventory.h"
#include "SlateOptMacros.h"

#include "SBoxPanel.h"
#include "SScaleBox.h"
#include "SBorder.h"
#include "SBox.h"

#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInventory::Construct(const FArguments& InArgs)
{
	//TitleInventory = InArgs._TitleInventory;
	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		//.WidthOverride(400)
		.HeightOverride(350)
		[
			SNew(SBorder)
			.BorderImage(&EmptySlotStyle->BackingBrush)
			.BorderBackgroundColor(EmptySlotStyle->EquipBackgroundColor.GetSpecifiedColor())
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(0)
			[
				
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.MaxHeight(50)
				.AutoHeight()
				.Padding(0)
				[
					SNew(STitleBar)
					.TitleName(FText().FromString("Inventory"))
				]
				+ SVerticalBox::Slot()
				.Padding(0)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SGridInventory)
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
