// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Hero/SHeroWindowWidget.h"
#include "SlateOptMacros.h"

#include "SScaleBox.h"
#include "SBox.h"
#include "SBorder.h"
#include "SBoxPanel.h"
#include "SButton.h"

#include "UI/STitleBar.h"
#include "UI/Equip/SEquip.h"
#include "UI/Stats/SStatsWidget.h"
#include "UI/Inventory/SInventory.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHeroWindowWidget::Construct(const FArguments& InArgs)
{
	
	ChildSlot
	[
		// Populate the widget
		SNew(SScaleBox)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SBox)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.HeightOverride(950)
			.WidthOverride(900)
		[
				SNew(SBorder)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					.MaxHeight(50)
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.FillWidth(10.0)
						.VAlign(VAlign_Fill)
						.HAlign(HAlign_Fill)
						[
							SNew(STitleBar)
							.TitleName(FText().FromString("Character"))
						]
						+ SHorizontalBox::Slot()
						.AutoWidth()
						.VAlign(VAlign_Fill)
						.HAlign(HAlign_Fill)
						[
							SNew(SButton)
							.Text(FText().FromString("X"))
						]
					]
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)	
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						[
							SNew(SEquip)
						]
						+ SHorizontalBox::Slot()
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Fill)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(SStatsWidget)
							]
							/*+ SVerticalBox::Slot()
							.HAlign(HAlign_Fill)
							.VAlign(VAlign_Fill)
							[
								SNew(SInventory)
							]*/
						]
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
