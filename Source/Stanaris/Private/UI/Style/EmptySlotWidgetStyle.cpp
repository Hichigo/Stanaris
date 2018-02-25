// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Style/EmptySlotWidgetStyle.h"


FEmptySlotStyle::FEmptySlotStyle()
{
}

FEmptySlotStyle::~FEmptySlotStyle()
{
}

const FName FEmptySlotStyle::TypeName(TEXT("FEmptySlotStyle"));

const FEmptySlotStyle& FEmptySlotStyle::GetDefault()
{
	static FEmptySlotStyle Default;
	return Default;
}

void FEmptySlotStyle::GetResources(TArray<const FSlateBrush*>& OutBrushes) const
{
	TextEntryStyle.GetResources(OutBrushes);

	// Add any brush resources here so that Slate can correctly atlas and reference them
	OutBrushes.Add(&BackgroundBrush);

}

UEmptySlotWidgetStyle::UEmptySlotWidgetStyle(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}