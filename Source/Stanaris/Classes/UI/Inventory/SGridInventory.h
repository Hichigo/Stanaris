// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "UI/Inventory/SEmptySlot.h"

/**
 * 
 */
class STANARIS_API SGridInventory : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGridInventory)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
