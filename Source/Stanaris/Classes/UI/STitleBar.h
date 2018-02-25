// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SThrobber.h"

#include "SlateColorBrush.h"

/**
 * 
 */
class STANARIS_API STitleBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(STitleBar)
	{}

	SLATE_ATTRIBUTE(FText, TitleName)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	const struct FEmptySlotStyle* EmptySlotStyle;

private:
	TAttribute<FText> TitleName;

	FSlateColorBrush* BackgroundColor;
};
