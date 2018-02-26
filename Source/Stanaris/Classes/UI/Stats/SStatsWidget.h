// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

#include "SThrobber.h"

#include "UI/STitleBar.h"

/**
 * 
 */
class STANARIS_API SStatsWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SStatsWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	const struct FEmptySlotStyle* EmptySlotStyle;

private:
	FSlateColorBrush* BackgroundColor;
};
