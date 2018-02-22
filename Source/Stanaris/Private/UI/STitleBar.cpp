// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/STitleBar.h"
#include "SlateOptMacros.h"

#include "SScaleBox.h"
#include "SBorder.h"
#include "SBox.h"
#include "STextBlock.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void STitleBar::Construct(const FArguments& InArgs)
{

	TitleName = InArgs._TitleName;
	
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
			//.BorderImage()
			[
				SNew(STextBlock)
				.Font(FSlateFontInfo("Arial", 26))
				.Text(TitleName)
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
