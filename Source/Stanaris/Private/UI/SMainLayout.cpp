// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/SMainLayout.h"
#include "SlateOptMacros.h"

#include "SOverlay.h"
#include "UI/Hero/SHeroWindowWidget.h"

#include "UI/Stats/SStatsWidget.h"
#include "UI/Equip/SEquip.h"
#include "UI/Inventory/SInventory.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainLayout::Construct(const FArguments& InArgs)
{
	
	//TSharedPtr<SInventory> Equip = SNew(SInventory);
	//TSharedPtr<SStatsWidget> Equip = SNew(SStatsWidget);
	//TSharedPtr<SEquip> Equip = SNew(SEquip);
	
	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SHeroWindowWidget)
			//Equip.ToSharedRef()
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
