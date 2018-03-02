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

#include "Engine.h"

#include "Hero/HeroPawn.h"

#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SStatsWidget::Construct(const FArguments& InArgs)
{
	//Level = InArgs._Level;

	

	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	TSharedPtr<STitleBar> TitleText = SNew(STitleBar);

	TSharedPtr<SStatsTextWidget> StatText = SNew(SStatsTextWidget);
	

	TSharedPtr<SVerticalBox> MainStats = SNew(SVerticalBox);
	MainStats->AddSlot()
	[
		SAssignNew(TitleText, STitleBar)
		.TitleName(FText().FromString("Main"))
	];
	
	//InArgs._OnUpdateLevel.BindRaw(this, &UStatsComp::OnUpdateLevel);
	//Level.Bind(this, &UStatsComp::OnUpdateLevel);
	Level.Bind(this, &SStatsWidget::OnUpdateLevel);
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Level"))
		.StatValue(Level)		
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Experience"))
		.StatValue(FText().FromString("909"))
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Health"))
		.StatValue(FText().FromString("909"))
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina"))
		.StatValue(FText().FromString("909"))
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
		.StatValue(FText().FromString("909"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Health point"))
		.StatValue(FText().FromString("909"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina point"))
		.StatValue(FText().FromString("909"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Strength point"))
		.StatValue(FText().FromString("909"))
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Agility point"))
		.StatValue(FText().FromString("909"))
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
		.StatValue(FText().FromString("909"))
	];
	SecondStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina regeneration %"))
		.StatValue(FText().FromString("909"))
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
		.StatValue(FText().FromString("909"))
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
		.StatValue(FText().FromString("909"))
	];


	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		//.WidthOverride(400)
		.HeightOverride(550)
		[
			SNew(SBorder)
			.BorderImage(&EmptySlotStyle->BackingBrush)
			.BorderBackgroundColor(EmptySlotStyle->StatsBackgroundColor.GetSpecifiedColor())
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(0)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.MaxHeight(50)
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SAssignNew(TitleText, STitleBar)
					.TitleName(FText().FromString("Stats"))
				]
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SScrollBox)
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
	];
	

}

FText SStatsWidget::OnUpdateLevel() const
{
	//GEngine->GetWorld()->GetPawnIterator()
	//AHeroPawn* Hero = Cast<AHeroPawn>(UGameplayStatics::GetPlayerCharacter(GEngine->GetWorld(), 0));
	//int32 Level = -100;
	//if (Hero != nullptr)
	//{
//		UE_LOG(LogTemp, Warning, TEXT("Hero not null"));
//		Level = Hero->FindComponentByClass<UStatsComp>()->GetLevel();
	//}
	
	UE_LOG(LogTemp, Warning, TEXT("%d"), 55);
	return FText().FromString("loh");//.AsNumber(Level);
}



END_SLATE_FUNCTION_BUILD_OPTIMIZATION
