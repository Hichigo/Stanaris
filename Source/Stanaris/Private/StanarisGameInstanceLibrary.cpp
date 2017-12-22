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
