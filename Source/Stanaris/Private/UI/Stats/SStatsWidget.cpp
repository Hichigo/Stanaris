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



#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SStatsWidget::Construct(const FArguments& InArgs)
{
	//HUD = InArgs._HUD;
	Level = InArgs._Level;

	/*
	AHeroPawn* Hero = Cast<AHeroPawn>(UGameplayStatics::GetPlayerCharacter(GEngine->GetWorld(), 0));
	
	if (Hero != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hero not null"));
		//Hero->FindComponentByClass<UStatsComp>()->OnUpdateLevel.AddDynamic(this, &SStatsWidget::UpdateLevel);
	}
	*/

	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	TSharedPtr<STitleBar> TitleText = SNew(STitleBar);

	TSharedPtr<SStatsTextWidget> StatText = SNew(SStatsTextWidget);
	

	TSharedPtr<SVerticalBox> MainStats = SNew(SVerticalBox);
	MainStats->AddSlot()
	[
		SAssignNew(TitleText, STitleBar)
		.TitleName(FText().FromString("Main"))
	];
	
	Level.Bind(this, &SStatsWidget::UpdateLevel); // this work for update every tick

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
		.StatValue(Expirience)
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Health"))
		.StatValue(Health)
	];
	MainStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina"))
		.StatValue(Stamina)
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
		.StatValue(AttributePoints)
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Health point"))
		.StatValue(HealthPoint)
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina point"))
		.StatValue(StaminaPoint)
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Strength point"))
		.StatValue(StrengthPoint)
	];
	Attributes->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Agility point"))
		.StatValue(AgilityPoint)
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
		.StatValue(HealthRegen)
	];
	SecondStats->AddSlot()
	[
		SAssignNew(StatText, SStatsTextWidget)
		.StatName(FText().FromString("Stamina regeneration %"))
		.StatValue(StaminaRegen)
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
		.StatValue(Damage)
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
		.StatValue(Defense)
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

void SStatsWidget::UpdateLevel(int32 NewLvl)
{
	Level.Set(FText::AsNumber(NewLvl));
	UE_LOG(LogTemp, Warning, TEXT("Level %d"), NewLvl);
}

void SStatsWidget::Bind()
{
	//Level.Bind(StatsRef, &UStatsComp::GetStaminaText);
}

FText SStatsWidget::UpdateLevel() const
{

	UE_LOG(LogTemp, Warning, TEXT("Level"));
	return FText::AsNumber(44);
	
	//return FText::AsNumber(StatsRef->Stats.Level);
}





END_SLATE_FUNCTION_BUILD_OPTIMIZATION
