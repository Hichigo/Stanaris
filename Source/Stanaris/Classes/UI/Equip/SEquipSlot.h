// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UI/Inventory/SEmptySlot.h"

/**
 * 
 */
class SEmptySlot;

class STANARIS_API SEquipSlot : public SEmptySlot
{
public:
	SLATE_BEGIN_ARGS(SEquipSlot)
	{}
	
	SLATE_ATTRIBUTE(int32, IndexSlot)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	const struct FEmptySlotStyle* EmptySlotStyle;
};
