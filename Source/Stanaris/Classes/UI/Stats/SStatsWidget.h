// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
//#include "Game/StanarisHUD.h"
//#include "Hero/HeroPawn.h"

#include "SThrobber.h"

#include "UI/STitleBar.h"


/**
 * 
 */
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTestDelegate);

class STANARIS_API SStatsWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SStatsWidget)
		: _Level(),
		_Health(),
		_Stamina(),
		_AttributePoints(),
		_HealthPoint(),
		_StaminaPoint(),
		_StrengthPoint(),
		_AgilityPoint(),
		_HealthRegen(),
		_StaminaRegen(),
		_Damage(),
		_Defense()
	{}

	//SLATE_ARGUMENT(TWeakObjectPtr<class AStanarisHUD>, HUD)
	SLATE_ATTRIBUTE(FText, Level)
	SLATE_ATTRIBUTE(FText, Expirience)
	SLATE_ATTRIBUTE(FText, Health)
	SLATE_ATTRIBUTE(FText, Stamina)
	SLATE_ATTRIBUTE(FText, AttributePoints)
	SLATE_ATTRIBUTE(FText, HealthPoint)
	SLATE_ATTRIBUTE(FText, StaminaPoint)
	SLATE_ATTRIBUTE(FText, StrengthPoint)
	SLATE_ATTRIBUTE(FText, AgilityPoint)
	SLATE_ATTRIBUTE(FText, HealthRegen)
	SLATE_ATTRIBUTE(FText, StaminaRegen)
	SLATE_ATTRIBUTE(FText, Damage)
	SLATE_ATTRIBUTE(FText, Defense)

	//SLATE_EVENT(FStatsEvents, OnUpdateLevel) // for work click

	SLATE_END_ARGS()

	//TWeakObjectPtr<class AStanarisHUD> HUD;

	TAttribute<FText> Level;
	TAttribute<FText> Expirience;
	TAttribute<FText> Health;
	TAttribute<FText> Stamina;
	TAttribute<FText> AttributePoints;
	TAttribute<FText> HealthPoint;
	TAttribute<FText> StaminaPoint;
	TAttribute<FText> StrengthPoint;
	TAttribute<FText> AgilityPoint;
	TAttribute<FText> HealthRegen;
	TAttribute<FText> StaminaRegen;
	TAttribute<FText> Damage;
	TAttribute<FText> Defense;


public:
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	const struct FEmptySlotStyle* EmptySlotStyle;

	void UpdateLevel(int32 NewLvl);

	//UStatsComp* StatsRef;


	void Bind();

private:
	//FSlateColorBrush* BackgroundColor;

	//FStatsEvents OnUpdate;

	//FStatsEvents OnUpdateLevel;

	UFUNCTION()
	FText UpdateLevel() const;
	
};
