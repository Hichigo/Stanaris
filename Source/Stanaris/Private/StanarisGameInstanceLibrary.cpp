// Fill out your copyright notice in the Description page of Project Settings.

#include "StanarisGameInstanceLibrary.h"

#include "Engine.h"


UStanarisGameInstanceLibrary::UStanarisGameInstanceLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

UStanarisGameInstance * UStanarisGameInstanceLibrary::GetGameInstance(UObject * WorldContextObject, bool & IsValid)
{
	IsValid = false;
	UWorld * World = GetRealWorld(WorldContextObject);

	UStanarisGameInstance * GameInstance = Cast<UStanarisGameInstance>(World->GetGameInstance());

	if (GameInstance != nullptr)
	{
		IsValid = true;
		return GameInstance;
	}

	return nullptr;
}

UWorld * UStanarisGameInstanceLibrary::GetRealWorld(UObject * WorldContextObject)
{
	return GEngine->GetWorldFromContextObjectChecked(WorldContextObject);
}

TArray<FDataItems> UStanarisGameInstanceLibrary::GetDataItems(UObject * WorldContextObject, bool & IsValid)
{
	IsValid = false;
	
	UStanarisGameInstance * GameInstance = GetGameInstance(WorldContextObject, IsValid);


	if (IsValid)
	{
		return GameInstance->DataEquipment;
	}

	return TArray<FDataItems>();
}

FDataItems UStanarisGameInstanceLibrary::GetDataItemById(int32 FindId, UObject * WorldContextObject, bool & IsValid)
{
	TArray<FDataItems> Items = GetDataItems(WorldContextObject, IsValid);
	if (IsValid)
	{
		for (FDataItems Item : Items)
		{
			if (Item.id == FindId)
			{
				return Item;
			}
		}
	}

	IsValid = false;
	return FDataItems();
}

ETypeItem UStanarisGameInstanceLibrary::DetectTypeItemById(int32 IdItem)
{
	// 0 - 999 -> equip
	// 1000 - 1999 -> used
	// 2000 - 2999 -> quest
	// 3000 - 3999 -> craft
	if (IdItem >= 0 && IdItem < 1000)
	{
		return ETypeItem::Equip;
	}

	if (IdItem >= 1000 && IdItem < 2000)
	{
		return ETypeItem::Used;
	}

	if (IdItem >= 2000 && IdItem < 3000)
	{
		return ETypeItem::Quest;
	}

	if (IdItem >= 3000 && IdItem < 4000)
	{
		return ETypeItem::Craft;
	}

	return ETypeItem();
}
