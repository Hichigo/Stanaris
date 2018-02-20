// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Inventory/SEmptySlot.h"
#include "ConstructorHelpers.h"
#include "Engine/Texture.h"
#include "SlateOptMacros.h"
#include "SBox.h"
#include "SBorder.h"
#include "UI/Style/EmptySlotWidgetStyle.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SEmptySlot::Construct(const FArguments& InArgs)
{
	


	const ConstructorHelpers::FObjectFinder<UTexture> MyImage(TEXT("Texture2D'/Game/Stanaris/Hero/UI/Textures/T_EmptySlot.T_EmptySlot'"));

	ChildSlot
		[
			// Populate the widget
			SNew(SBox)
			.WidthOverride(50)
			.HeightOverride(50)
			[
				SNew(SBorder)
				//.BorderImage()
			]
	];
	
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
