// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

#include "SGridPanel.h"
#include "SThrobber.h"

#include "UI/STitleBar.h"

/**
 * 
 */
class STANARIS_API SEquip : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SEquip)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);



private:
	void InitEquipSlot(class TSharedPtr<SGridPanel> EquipContainer, int32 Column, int32 Row, int32 ColumnSpan, int32 RowSpan, int32 Index);

	FSlateColorBrush* BackgroundColor;
};
