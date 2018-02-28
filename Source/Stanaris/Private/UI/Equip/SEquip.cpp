// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Equip/SEquip.h"
#include "SlateOptMacros.h"


#include "UI/Equip/SEquipSlot.h"
#include "SBoxPanel.h"
//#include "SGridPanel.h"
#include "SScaleBox.h"
#include "SBorder.h"
#include "SBox.h"

#include "UI/Style/EmptySlotWidgetStyle.h"
#include "UI/Style/InventoryStyle.h"



BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEquip::Construct(const FArguments& InArgs)
{
	
	EmptySlotStyle = &FInventoryStyle::Get().GetWidgetStyle<FEmptySlotStyle>("WS_EmptySlot"); // get asset from editor 

	TSharedPtr<SGridPanel> EquipContainer = SNew(SGridPanel);
	
	EquipContainer->SetRowFill(0, 1.f);
	EquipContainer->SetRowFill(1, 1.f);
	EquipContainer->SetRowFill(2, 1.f);
	EquipContainer->SetRowFill(3, 1.f);
	EquipContainer->SetRowFill(4, 1.f);
	EquipContainer->SetRowFill(5, 1.f);
	EquipContainer->SetRowFill(6, 1.f);
	EquipContainer->SetRowFill(7, 1.f);
	EquipContainer->SetRowFill(8, 1.f);
	EquipContainer->SetRowFill(9, 1.f);
	EquipContainer->SetRowFill(10, 1.f);
	EquipContainer->SetRowFill(11, 1.f);
	EquipContainer->SetRowFill(12, 1.f);
	EquipContainer->SetRowFill(13, 1.f);
	EquipContainer->SetRowFill(14, 1.f);
	EquipContainer->SetRowFill(15, 1.f);
	EquipContainer->SetRowFill(16, 1.f);

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
	InitEquipSlot(EquipContainer, 4, 1, 2, 2, 0);
	//neck
	InitEquipSlot(EquipContainer, 7, 2, 1, 1, 1);
	//right hand
	InitEquipSlot(EquipContainer, 1, 4, 3, 2, 2);
	//left hand
	InitEquipSlot(EquipContainer, 7, 4, 3, 2, 3);
	//right ring
	InitEquipSlot(EquipContainer, 1, 8, 1, 1, 4);
	//left ring
	InitEquipSlot(EquipContainer, 8, 8, 1, 1, 5);
	//body
	InitEquipSlot(EquipContainer, 1, 10, 3, 2, 6);
	//pants
	InitEquipSlot(EquipContainer, 7, 10, 3, 2, 7);
	//gloves
	InitEquipSlot(EquipContainer, 1, 14, 2, 2, 8);
	//boots
	InitEquipSlot(EquipContainer, 7, 14, 2, 2, 9);


	//unuse
	EquipContainer->AddSlot(0, 16)
	.RowSpan(0)
	.ColumnSpan(10)
	[
		SNew(SBorder)
		.Padding(0)
	];


	
	ChildSlot
	[
		// Populate the widget
		SNew(SBox)
		.WidthOverride(500)
		.HeightOverride(900)
		[
			SNew(SBorder)
			//.BorderImage(&EmptySlotStyle->BackingBrush)
			.BorderBackgroundColor(EmptySlotStyle->EquipBackgroundColor.GetSpecifiedColor())
			.Padding(0)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.MaxHeight(50)
				.AutoHeight()
				.HAlign(HAlign_Fill)
				[
					SNew(STitleBar)
					.TitleName(FText().FromString("Equipment"))
				]
				+ SVerticalBox::Slot()
				.VAlign(VAlign_Fill)
				.HAlign(HAlign_Fill)
				[
					EquipContainer.ToSharedRef()
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
