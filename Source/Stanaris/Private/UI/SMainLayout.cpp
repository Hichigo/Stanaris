// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/SMainLayout.h"
#include "SlateOptMacros.h"

#include "SOverlay.h"
#include "UI/Hero/SHeroWindowWidget.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainLayout::Construct(const FArguments& InArgs)
{

	HUD = InArgs._HUD;
		
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		[
			SNew(SHeroWindowWidget).HUD(HUD.Get())
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
