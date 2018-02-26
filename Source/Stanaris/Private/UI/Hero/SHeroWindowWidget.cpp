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
		[
			SNew(SBox)
			.HeightOverride(950)
			.WidthOverride(900)
			[
				SNew(SBorder)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						[
							SNew(STitleBar)
							.TitleName(FText().FromString("Character"))
						]
						+ SHorizontalBox::Slot()
						[
							SNew(SButton)
							.Text(FText().FromString("X"))
						]
					]
					+ SVerticalBox::Slot()
					[
						SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						[
							SNew(SEquip)
						]
						+ SHorizontalBox::Slot()
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SStatsWidget)
							]
							+ SVerticalBox::Slot()
							[
								SNew(SInventory)
							]
						]
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
