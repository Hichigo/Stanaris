// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateWidgetStyle.h"
#include "SlateWidgetStyleContainerBase.h"
#include "SlateTypes.h"

#include "EmptySlotWidgetStyle.generated.h"

/**
 * 
 */
USTRUCT()
struct STANARIS_API FEmptySlotStyle : public FSlateWidgetStyle
{
	GENERATED_USTRUCT_BODY()

	FEmptySlotStyle();
	virtual ~FEmptySlotStyle();

	// FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*>& OutBrushes) const override;

	static const FName TypeName;

	virtual const FName GetTypeName() const override { return TypeName; };

	static const FEmptySlotStyle& GetDefault();

	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateBrush BackgroundBrush;
	FEmptySlotStyle& SetBackgroundBrush(const FSlateBrush& InBackgroundBrush) { BackgroundBrush = InBackgroundBrush; return *this; }

	UPROPERTY(EditAnywhere, Category = Appearance)
	FEditableTextBoxStyle TextEntryStyle;
	FEmptySlotStyle& SetTextEntryStyle(const FEditableTextBoxStyle& InTextEntryStyle) { TextEntryStyle = InTextEntryStyle; return *this; }


	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateColor EquipBackgroundColor;
	FEmptySlotStyle& SetEquipBackgroundColor(const FSlateColor& InEquipBackgroundColor) { EquipBackgroundColor = InEquipBackgroundColor; return *this; }

	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateColor StatsBackgroundColor;
	FEmptySlotStyle& SetStatsBackgroundColor(const FSlateColor& InStatsBackgroundColor) { StatsBackgroundColor = InStatsBackgroundColor; return *this; }

	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateColor InventoryBackgroundColor;
	FEmptySlotStyle& SetInventoryBackgroundColor(const FSlateColor& InInventoryBackgroundColor) { InventoryBackgroundColor = InInventoryBackgroundColor; return *this; }

	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateColor CommonTitleBarBackgroundColor;
	FEmptySlotStyle& SetCommonTitleBarBackgroundColor(const FSlateColor& InCommonTitleBarBackgroundColor) { CommonTitleBarBackgroundColor = InCommonTitleBarBackgroundColor; return *this; }

	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateBrush BackingBrush;
	FEmptySlotStyle& SetBackingBrush(const FSlateBrush& InBackingBrush) { BackingBrush = InBackingBrush; return *this; }


};

/**
 */
UCLASS(hidecategories=Object, MinimalAPI)
class UEmptySlotWidgetStyle : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()

public:

	UEmptySlotWidgetStyle(const FObjectInitializer& ObjectInitializer);

	/** The actual data describing the widget appearance. */
	UPROPERTY(Category=Appearance, EditAnywhere, meta=(ShowOnlyInnerProperties))
	FEmptySlotStyle WidgetStyle;

	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >( &WidgetStyle );
	}
};
