// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Game/StanarisHUD.h"

#include "SThrobber.h"

/**
 * 
 */
class STANARIS_API SHeroWindowWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHeroWindowWidget)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<class AStanarisHUD>, HUD)

	SLATE_EVENT(FOnClicked, OnClicked) // for work click

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AStanarisHUD> HUD;

	FORCEINLINE TSharedPtr<class SStatsWidget> GetStatsWidget() const { return StatsWidget; }

private:
	FOnClicked OnClicked; // for work click

	FReply OnHideInventory();

	TSharedPtr<class SStatsWidget> StatsWidget;
};
