// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/SInventory.h"
#include "SlateOptMacros.h"

#include "SBoxPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInventory::Construct(const FArguments& InArgs)
{
	TitleInventory = InArgs._TitleInventory;


	
	ChildSlot
	[
		// Populate the widget
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.MaxHeight(50)
		[
			SNew(STitleBar)
			.TitleName(FText().FromString("Inventory"))
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SGridInventory)
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
