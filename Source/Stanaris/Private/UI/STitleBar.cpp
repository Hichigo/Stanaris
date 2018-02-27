// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/STitleBar.h"
#include "SlateOptMacros.h"

#include "SScaleBox.h"
#include "SBorder.h"
#include "SBox.h"
#include "STextBlock.h"

#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"



BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STitleBar::Construct(const FArguments& InArgs)
{

	TitleName = InArgs._TitleName;
	
	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	FSlateColorBrush BackgroundColor = FSlateColorBrush(FLinearColor::Green);

	ChildSlot
	[
		// Populate the widget
		SNew(SScaleBox)
		//.Stretch(EStretch::ScaleToFit)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SBorder)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			//.ColorAndOpacity(FLinearColor(1.f, 0.f, 0.f, 1.f))
			.BorderImage(&BackgroundColor)
			//.BorderImage()
			[
				SNew(SBox)
				.HeightOverride(50)
				//.HAlign(HAlign_Fill)
				//.VAlign(VAlign_Fill)
				[
					SNew(STextBlock)
					.Font(FSlateFontInfo(EmptySlotStyle->TextEntryStyle.Font))
					.Text(TitleName)
					.Justification(ETextJustify::Center)
					.ColorAndOpacity(FLinearColor(1., 0., 0., 1.))
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
