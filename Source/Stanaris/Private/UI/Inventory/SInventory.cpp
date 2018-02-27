// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/SInventory.h"
#include "SlateOptMacros.h"

#include "SBoxPanel.h"
#include "SScaleBox.h"
#include "SBorder.h"
#include "SBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInventory::Construct(const FArguments& InArgs)
{
	//TitleInventory = InArgs._TitleInventory;


	
	ChildSlot
	[
		// Populate the widget
		SNew(SScaleBox)
		//.HAlign(HAlign_Fill)
		//.VAlign(VAlign_Fill)
		[
			SNew(SBorder)
			//.HAlign(HAlign_Fill)
			//.VAlign(VAlign_Fill)
			[
				SNew(SBox)
				.WidthOverride(400)
				.HeightOverride(350)
				//.HAlign(HAlign_Fill)
				//.VAlign(VAlign_Fill)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.MaxHeight(50)
					.AutoHeight()
					[
						SNew(STitleBar)
						.TitleName(FText().FromString("Inventory"))
					]
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SGridInventory)
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
