// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

#include "UI/STitleBar.h"
#include "UI/Inventory/SGridInventory.h"

/**
 * 
 */
class STANARIS_API SInventory : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInventory)
	{}

	//SLATE_ATTRIBUTE(FText, TitleInventory)


	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	const struct FEmptySlotStyle* EmptySlotStyle;

private:
	//TAttribute<FText> TitleInventory;
};
