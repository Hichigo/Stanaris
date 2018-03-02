// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

#include "SThrobber.h"

#include "Hero/Components/StatsComp.h"

#include "UI/STitleBar.h"

/**
 * 
 */
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestDelegate);

class STANARIS_API SStatsWidget : public SCompoundWidget
{
	//DECLARE_DELEGATE(FStatsEvents);

	SLATE_BEGIN_ARGS(SStatsWidget)
	{}

	//SLATE_ATTRIBUTE(FText, Level)

	//SLATE_EVENT(FStatsEvents, OnUpdateLevel) // for work click

	SLATE_END_ARGS()

	TAttribute<FText> Level;

public:
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	const struct FEmptySlotStyle* EmptySlotStyle;

private:
	FSlateColorBrush* BackgroundColor;

	//FStatsEvents OnUpdate;

	//FStatsEvents OnUpdateLevel;

	
	FText OnUpdateLevel() const;
};
