// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Equip/SEquip.h"
#include "SlateOptMacros.h"

#include "UI/STitleBar.h"
#include "UI/Equip/SEquipSlot.h"
#include "SBoxPanel.h"
#include "SGridPanel.h"
#include "SScaleBox.h"
#include "SBorder.h"
#include "SBox.h"
#include "SOverlay.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEquip::Construct(const FArguments& InArgs)
{
	

	TSharedPtr<SGridPanel> GridInventoryContainer = SNew(SGridPanel);

	GridInventoryContainer->SetRowFill(0, 1.f);
	GridInventoryContainer->SetRowFill(1, 1.f);
	GridInventoryContainer->SetRowFill(2, 1.f);
	GridInventoryContainer->SetRowFill(3, 1.f);
	GridInventoryContainer->SetRowFill(4, 1.f);
	GridInventoryContainer->SetRowFill(5, 1.f);

	GridInventoryContainer->SetColumnFill(0, 1.f);
	GridInventoryContainer->SetColumnFill(1, 1.f);
	GridInventoryContainer->SetColumnFill(2, 1.f);
	GridInventoryContainer->SetColumnFill(3, 1.f);
	GridInventoryContainer->SetColumnFill(4, 1.f);
	GridInventoryContainer->SetColumnFill(5, 1.f);
	GridInventoryContainer->SetColumnFill(6, 1.f);
	GridInventoryContainer->SetColumnFill(7, 1.f);
	GridInventoryContainer->SetColumnFill(8, 1.f);
	GridInventoryContainer->SetColumnFill(9, 1.f);

	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(SScaleBox)
			[
				SNew(SBorder)
				[
					SNew(SBox)
					.WidthOverride(500)
					.HeightOverride(900)
					[
						SNew(SVerticalBox)
						+SVerticalBox::Slot()
						.MaxHeight(50)
						[
							SNew(STitleBar)
							.TitleName(FText().FromString("Equipment"))
						]
						+SVerticalBox::Slot()
						.AutoHeight()
						[
							GridInventoryContainer.ToSharedRef()
						]
					]
				]
			]
		]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
