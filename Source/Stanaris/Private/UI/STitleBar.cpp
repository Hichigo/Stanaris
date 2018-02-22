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
	[
		// Populate the widget
		SNew(SScaleBox)
		//.Stretch(EStretch::ScaleToFit)
		[
			SNew(SBorder)
			//.BorderImage()
			[
				SNew(STextBlock)
				.Text(TitleName)
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
