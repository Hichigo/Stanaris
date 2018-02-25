// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Stats/SStatsTextWidget.h"
#include "SlateOptMacros.h"

#include "SScaleBox.h"
#include "SBox.h"
#include "SBoxPanel.h"
#include "STextBlock.h"

#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SStatsTextWidget::Construct(const FArguments& InArgs)
{

	StatName = InArgs._StatName;

	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	
	ChildSlot
	[
		// Populate the widget
		SNew(SScaleBox)
		[
			SNew(SBox)
			.WidthOverride(400)
			.HeightOverride(50)
			.HAlign(HAlign_Fill)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.AutoWidth()
				.MaxWidth(300)
				.HAlign(HAlign_Fill)
				[
					SNew(STextBlock)
					.Font(FSlateFontInfo(EmptySlotStyle->TextEntryStyle.Font))
					.Text(StatName)
					.ColorAndOpacity(FLinearColor(0., 1., 0., 1.))
				]
				+ SHorizontalBox::Slot()
				[
					SNew(STextBlock)
					.Font(FSlateFontInfo(EmptySlotStyle->TextEntryStyle.Font))
					.Text(FText().FromString("999"))
					.Justification(ETextJustify::Right)
					.ColorAndOpacity(FLinearColor(0., 1., 0., 1.))
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
