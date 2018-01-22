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

//TArray<FDataItems> UStanarisGameInstanceLibrary::GetDataItems(UObject * WorldContextObject, bool & IsValid)
//{
//	IsValid = false;
//	
//	UStanarisGameInstance * GameInstance = GetGameInstance(WorldContextObject, IsValid);
//
//
//	if (IsValid)
//	{
//		return GameInstance->DataEquipment;
//	}
//
//	return TArray<FDataItems>();
//}

//FDataItems UStanarisGameInstanceLibrary::GetDataItemById(int32 FindId, UObject * WorldContextObject, bool & IsValid)
//{
//	TArray<FDataItems> Items = GetDataItems(WorldContextObject, IsValid);
//	if (IsValid)
//	{
//		for (FDataItems Item : Items)
//		{
//			if (Item.id == FindId)
//			{
//				return Item;
//			}
//		}
//	}
//
//	IsValid = false;
//	return FDataItems();
//}

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

void UStanarisGameInstanceLibrary::GetItemFromTableById(int32 IdItem,
	TArray<UDataTable*> Tables,
	ETypeItem &TypeItem,
	FEquipItemData &EquipItemData,
	FUsedItemData &UsedItemData,
	FQuestItemData &QuestItemData,
	FCraftItemData &CraftItemData)
{
	EquipItemData = FEquipItemData();
	CraftItemData = FCraftItemData();
	UsedItemData = FUsedItemData();
	QuestItemData = FQuestItemData();

	TypeItem = DetectTypeItemById(IdItem);

	
	switch (TypeItem)
	{
	case ETypeItem::Equip:
		EquipItemData = FindEquipItemById(Tables[0], IdItem); // equip table
		return;
	case ETypeItem::Used:
		UsedItemData = FindUsedItemById(Tables[1], IdItem); // used table
		return;
	case ETypeItem::Quest:
		QuestItemData = FindQuestItemById(Tables[2], IdItem); // quest table
		return;
	case ETypeItem::Craft:
		CraftItemData = FindCraftItemById(Tables[3], IdItem); // craft table
		return;
	default:
		UE_LOG(LogTemp, Error, TEXT("GetItemFromTableById wrong id item!"));
		return;
	}

}

FEquipItemData UStanarisGameInstanceLibrary::FindEquipItemById(UDataTable* EquipTable, int32 IdItem)
{
	FString ContextString; //error or warning
	
	TArray<FName> RowNames;
	RowNames = EquipTable->GetRowNames();

	for (auto& name : RowNames)
	{
		FEquipItemData *row = EquipTable->FindRow<FEquipItemData>(name, ContextString);

		if (row)
		{
			if (row->id == IdItem)
			{
				return (*row);
			}
		}
	}

	return FEquipItemData();
}

FCraftItemData UStanarisGameInstanceLibrary::FindCraftItemById(UDataTable * CraftTable, int32 IdItem)
{

	FString ContextString; //error or warning

	TArray<FName> RowNames;
	RowNames = CraftTable->GetRowNames();

	for (auto& name : RowNames)
	{
		FCraftItemData *row = CraftTable->FindRow<FCraftItemData>(name, ContextString);

		if (row)
		{
			if (row->id == IdItem)
			{
				return (*row);
			}
		}
	}

	return FCraftItemData();
}

FUsedItemData UStanarisGameInstanceLibrary::FindUsedItemById(UDataTable * UsedTable, int32 IdItem)
{
	FString ContextString; //error or warning

	TArray<FName> RowNames;
	RowNames = UsedTable->GetRowNames();

	for (auto& name : RowNames)
	{
		FUsedItemData *row = UsedTable->FindRow<FUsedItemData>(name, ContextString);

		if (row)
		{
			if (row->id == IdItem)
			{
				return (*row);
			}
		}
	}

	return FUsedItemData();
}

FQuestItemData UStanarisGameInstanceLibrary::FindQuestItemById(UDataTable * QuestTable, int32 IdItem)
{

	FString ContextString; //error or warning

	TArray<FName> RowNames;
	RowNames = QuestTable->GetRowNames();

	for (auto& name : RowNames)
	{
		FQuestItemData *row = QuestTable->FindRow<FQuestItemData>(name, ContextString);

		if (row)
		{
			if (row->id == IdItem)
			{
				return (*row);
			}
		}
	}

	return FQuestItemData();
}
