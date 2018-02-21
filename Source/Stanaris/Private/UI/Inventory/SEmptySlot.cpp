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
	
	/*
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(STextBlock)
			.ColorAndOpacity(FLinearColor::White)
			.ShadowColorAndOpacity(FLinearColor::Black)
			.ShadowOffset(FIntPoint(-1, 1))
			.Font(FSlateFontInfo("Arial", 26))
			.Text(FText::FromString("Main Menu"))
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Bottom)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.Text(FText::FromString("Play Game!"))
			]
			+ SVerticalBox::Slot()
			[
				SNew(SButton)
				.Text(FText::FromString("Quit Game"))
			]
		]
	];
	*/
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
