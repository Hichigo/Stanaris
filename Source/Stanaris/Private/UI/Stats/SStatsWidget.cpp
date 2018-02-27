// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Stats/SStatsWidget.h"
#include "SlateOptMacros.h"

#include "SOverlay.h"
#include "SScaleBox.h"
#include "SBox.h"
#include "SBorder.h"
#include "SBoxPanel.h"
#include "SScrollBox.h"
#include "UI/Stats/SStatsTextWidget.h"

#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SStatsWidget::Construct(const FArguments& InArgs)
{
	
	FSlateColorBrush BackgroundColor = FSlateColorBrush(FLinearColor::Gray);

	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	TSharedPtr<STitleBar> TitleText = SNew(STitleBar);

	TSharedPtr<SStatsTextWidget> StatText = SNew(SStatsTextWidget);

	TSharedPtr<SVerticalBox> MainStats = SNew(SVerticalBox);
	MainStats->AddSlot()
	[
		SAssignNew(TitleText, STitleBar)
		.TitleName(FText().FromString("Main"))
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Level"))
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Experience"))
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Health"))
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina"))
	];



	TSharedPtr<SVerticalBox> Attributes = SNew(SVerticalBox);
	Attributes->AddSlot()
	[
		SAssignNew(TitleText, STitleBar)
		.TitleName(FText().FromString("Attributes"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Attribute points"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Health point"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina point"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Strength point"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Agility point"))
	];


	TSharedPtr<SVerticalBox> SecondStats = SNew(SVerticalBox);
	SecondStats->AddSlot()
	[
		SAssignNew(TitleText, STitleBar)
		.TitleName(FText().FromString("Second"))
	];
	SecondStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Health regeneration/sec"))
	];
	SecondStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina regeneration %"))
	];


	TSharedPtr<SVerticalBox> AttackStats = SNew(SVerticalBox);
	SecondStats->AddSlot()
	[
		SAssignNew(TitleText, STitleBar)
		.TitleName(FText().FromString("Attack"))
	];
	SecondStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Damage"))
	];


	TSharedPtr<SVerticalBox> ArmorStats = SNew(SVerticalBox);
	SecondStats->AddSlot()
	[
		SAssignNew(TitleText, STitleBar)
		.TitleName(FText().FromString("Armor"))
	];
	SecondStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Defense"))
	];

	ChildSlot
	[
		// Populate the widget
		SNew(SScaleBox)
		[
			SNew(SBorder)
			.BorderImage(&EmptySlotStyle->BackgroundBrush)
			[
				SNew(SBox)
				.WidthOverride(400)
				.HeightOverride(550)
				//.MinDesiredWidth(400)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.AutoHeight()
					.MaxHeight(50)
					[
						SAssignNew(TitleText, STitleBar)
						.TitleName(FText().FromString("Stats"))
					]
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Fill)
					[
						SNew(SBox)
						.WidthOverride(400)
						.HeightOverride(500)
						[
							SNew(SScrollBox)
							.ScrollBarVisibility(EVisibility::Visible)
							+ SScrollBox::Slot() // main stats
							.HAlign(HAlign_Fill)
							[
								MainStats.ToSharedRef()
							]
							+ SScrollBox::Slot() // attribute
							.HAlign(HAlign_Fill)
							[
								Attributes.ToSharedRef()
							]
							+ SScrollBox::Slot() // second stats
							.HAlign(HAlign_Fill)
							[
								SecondStats.ToSharedRef()
							]
							+ SScrollBox::Slot() // attack stats
							.HAlign(HAlign_Fill)
							[
								AttackStats.ToSharedRef()
							]
							+ SScrollBox::Slot() // defense stats
							.HAlign(HAlign_Fill)
							[
								ArmorStats.ToSharedRef()
							]
						]
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
