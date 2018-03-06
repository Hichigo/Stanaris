// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Hero/SHeroWindowWidget.h"
#include "SlateOptMacros.h"

#include "SScaleBox.h"
#include "SBox.h"
#include "SBorder.h"
#include "SBoxPanel.h"
#include "SButton.h"
#include "SBackgroundBlur.h"

#include "UI/STitleBar.h"
#include "UI/Equip/SEquip.h"
#include "UI/Stats/SStatsWidget.h"
#include "UI/Inventory/SInventory.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHeroWindowWidget::Construct(const FArguments& InArgs)
{
	HUD = InArgs._HUD;
	OnClicked = InArgs._OnClicked; // for work click
	
	StatsWidget = SNew(SStatsWidget);

	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		//.HeightOverride(950) //950
		//.WidthOverride(900)
		[
			SNew(SBackgroundBlur)
			.BlurStrength(15.f)
			.Padding(0)
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
					//.AutoWidth()
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Fill)
					[
						SNew(STitleBar)
						.TitleName(FText().FromString("Character"))
					]
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.MaxWidth(50)
					.VAlign(VAlign_Fill)
					.HAlign(HAlign_Right)
					[
						SNew(SBox)
						.WidthOverride(50)
						.HeightOverride(50)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Text(FText().FromString("X"))
							.OnClicked(this, &SHeroWindowWidget::OnHideInventory)
						]
					]
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)	
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.AutoWidth()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					[
						SNew(SEquip)
					]
					+ SHorizontalBox::Slot()
					.HAlign(HAlign_Fill)
					.VAlign(VAlign_Fill)
					.AutoWidth()
					.MaxWidth(400)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.Padding(0)
						.HAlign(HAlign_Fill)
						.VAlign(VAlign_Top)
						.AutoHeight()
						[
							StatsWidget.ToSharedRef()
						]
						+ SVerticalBox::Slot()
						.HAlign(HAlign_Fill)
						//.VAlign(VAlign_Fill)
						.AutoHeight()
						.MaxHeight(350)
						[
							//Inventory.ToSharedRef()
							SNew(SInventory)
						]
					]
				]
			]
		]
	];
	
}
FReply SHeroWindowWidget::OnHideInventory()
{
	HUD->HideInventory();

	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
