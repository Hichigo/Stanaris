// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/SInventory.h"
#include "SlateOptMacros.h"

#include "SBoxPanel.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInventory::Construct(const FArguments& InArgs)
{
	TitleInventory = InArgs._TitleInventory;


	TSharedPtr<STitleBar> TitleInventory = SNew(STitleBar).TitleName(FText().FromString("Inventory"));
	TSharedPtr<SGridInventory> GridInventory = SNew(SGridInventory);
	
	ChildSlot
	[
		// Populate the widget
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.MaxHeight(50)
		[
			TitleInventory.ToSharedRef()
		]
		+ SVerticalBox::Slot()
		.AutoHeight()
		[
			GridInventory.ToSharedRef()
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
