// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Stats/SStatsWidget.h"
#include "SlateOptMacros.h"

#include "SOverlay.h"
#include "SScaleBox.h"
#include "SBox.h"
#include "SBorder.h"
#include "SBoxPanel.h"
#include "SScrollBox.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SStatsWidget::Construct(const FArguments& InArgs)
{
	
	FSlateColorBrush BackgroundColor = FSlateColorBrush(FLinearColor::Gray);

	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(SScaleBox)
			[
				SNew(SBorder)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.BorderImage(&BackgroundColor)
				[
					SNew(SBox)
					.WidthOverride(400)
					.HeightOverride(550)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.AutoHeight()
						.MaxHeight(50)
						[
							SNew(STitleBar)
							.TitleName(FText().FromString("Stats"))
						]
						+ SVerticalBox::Slot()
						[
							SNew(SScrollBox)
							+SScrollBox::Slot() // main stats
							[
								SNew(SVerticalBox)
							]
							+ SScrollBox::Slot() // attribute
							[
								SNew(SVerticalBox)
							]
							+ SScrollBox::Slot() // second stats
							[
								SNew(SVerticalBox)
							]
							+ SScrollBox::Slot() // attack stats
							[
								SNew(SVerticalBox)
							]
							+ SScrollBox::Slot() // defense stats
							[
								SNew(SVerticalBox)
							]
						]
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
