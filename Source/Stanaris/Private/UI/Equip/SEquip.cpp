// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Equip/SEquip.h"
#include "SlateOptMacros.h"

#include "UI/STitleBar.h"
#include "UI/Equip/SEquipSlot.h"
#include "SBoxPanel.h"
//#include "SGridPanel.h"
#include "SScaleBox.h"
#include "SBorder.h"
#include "SBox.h"
#include "SOverlay.h"


BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEquip::Construct(const FArguments& InArgs)
{
	

	TSharedPtr<SGridPanel> EquipContainer = SNew(SGridPanel);

	EquipContainer->SetRowFill(0, 1.f);
	EquipContainer->SetRowFill(1, 1.f);
	EquipContainer->SetRowFill(2, 1.f);
	EquipContainer->SetRowFill(3, 1.f);
	EquipContainer->SetRowFill(4, 1.f);
	EquipContainer->SetRowFill(5, 1.f);

	EquipContainer->SetColumnFill(0, 1.f);
	EquipContainer->SetColumnFill(1, 1.f);
	EquipContainer->SetColumnFill(2, 1.f);
	EquipContainer->SetColumnFill(3, 1.f);
	EquipContainer->SetColumnFill(4, 1.f);
	EquipContainer->SetColumnFill(5, 1.f);
	EquipContainer->SetColumnFill(6, 1.f);
	EquipContainer->SetColumnFill(7, 1.f);
	EquipContainer->SetColumnFill(8, 1.f);
	EquipContainer->SetColumnFill(9, 1.f);

	//helm
	//InitEquipSlot(EquipContainer, 4, 1, 2, 2, 0);
	EquipContainer->AddSlot(4, 1)
	.RowSpan(2)
	.ColumnSpan(2)
	[
		SNew(SEquipSlot)
		.IndexSlot(0)
	];






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
							EquipContainer.ToSharedRef()
						]
					]
				]
			]
		]
	];
	
}

void SEquip::InitEquipSlot(class TSharedPtr<SGridPanel> EquipContainer, int32 Column, int32 Row, int32 ColumnSpan, int32 RowSpan, int32 Index)
{
	EquipContainer->AddSlot(Column, Row)
	.RowSpan(ColumnSpan)
	.ColumnSpan(RowSpan)
	[
		SNew(SEquipSlot)
		.IndexSlot(Index)
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
