// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/Style/InventoryStyle.h"
#include "Stanaris.h"
#include "SlateGameResources.h" 


TSharedPtr<FSlateStyleSet> FInventoryStyle::InventoryStyleInstance = NULL;

void FInventoryStyle::Initialize()
{
	if (!InventoryStyleInstance.IsValid())
	{
		InventoryStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*InventoryStyleInstance);
	}
}

void FInventoryStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*InventoryStyleInstance);
	ensure(InventoryStyleInstance.IsUnique());
	InventoryStyleInstance.Reset();
}

const ISlateStyle & FInventoryStyle::Get()
{
	// TODO: insert return statement here
	return *InventoryStyleInstance;
}

FName FInventoryStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("MenuStyles"));
	return StyleSetName;
}

TSharedRef<class FSlateStyleSet> FInventoryStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FInventoryStyle::GetStyleSetName(), "/Game/Stanaris/Hero/UI/Styles", "/Game/Stanaris/Hero/UI/Styles");
	return StyleRef;
}
