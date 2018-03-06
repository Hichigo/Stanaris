// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "UI/Hero/SHeroWindowWidget.h"

#include "SThrobber.h"
/**
 * 
 */
class STANARIS_API SMainLayout : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainLayout)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<class AStanarisHUD>, HUD)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AStanarisHUD> HUD;

	FORCEINLINE TSharedPtr<class SHeroWindowWidget> GetHeroWidget() const { return HeroWidget; }

private:
	TSharedPtr<class SHeroWindowWidget> HeroWidget;
};
