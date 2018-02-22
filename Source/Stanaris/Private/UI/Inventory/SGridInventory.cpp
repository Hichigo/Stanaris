// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/SGridInventory.h"
#include "SlateOptMacros.h"

#include "SGridPanel.h"
#include "SBox.h"
#include "SOverlay.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SGridInventory::Construct(const FArguments& InArgs)
{
	TSharedPtr<SGridPanel> GridInventoryContainer = SNew(SGridPanel);

	int32 Index = 0;

	for (int32 j = 0; j < 6; j++) //row
	{
		GridInventoryContainer->SetRowFill(j, 1.0f);
		for (int32 i = 0; i < 8; i++) //column
		{
			if (j == 0)
			{
				GridInventoryContainer->SetColumnFill(i, 1.0f);
			}

			GridInventoryContainer->AddSlot(i, j)
			[
				SNew(SEmptySlot)
				.IndexSlot(Index)
			];
			Index++;
		}
	}


	ChildSlot
	[
		// Populate the widget
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Top)
		[
			SNew(SBox)
			.WidthOverride(400)
			.HeightOverride(300)
			[
				GridInventoryContainer.ToSharedRef()
			]
		]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
