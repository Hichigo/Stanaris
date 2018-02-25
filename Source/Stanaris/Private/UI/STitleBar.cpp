// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/STitleBar.h"
#include "SlateOptMacros.h"

#include "SScaleBox.h"
#include "SBorder.h"
#include "SBox.h"
#include "STextBlock.h"

#include "SlateColorBrush.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STitleBar::Construct(const FArguments& InArgs)
{

	TitleName = InArgs._TitleName;
	
	FSlateColorBrush brushClr = FSlateColorBrush(FLinearColor::White);

	ChildSlot
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Fill)
	[
		// Populate the widget
		SNew(SScaleBox)
		//.Stretch(EStretch::ScaleToFit)
		[
			SNew(SBorder)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.ColorAndOpacity(FLinearColor(1.f, 0.f, 0.f, 1.f))
			//.BorderImage(&brushClr)
			//.BorderImage()
			[
				SNew(STextBlock)
				.Font(FSlateFontInfo("Roboto", 26))
				.Text(TitleName)
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
