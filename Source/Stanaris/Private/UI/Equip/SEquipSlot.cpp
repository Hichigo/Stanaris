// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Equip/SEquipSlot.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEquipSlot::Construct(const FArguments& InArgs)
{
	IndexSlot = InArgs._IndexSlot;

	/*
	ChildSlot
	[
		// Populate the widget
	];
	*/
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
