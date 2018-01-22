// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "StanarisGameInstance.h"
#include "Engine/DataTable.h"
#include "Structures/Inventory/InventoryStructures.h"

#include "StanarisGameInstanceLibrary.generated.h"

/**
 * 
 */
UCLASS()
class STANARIS_API UStanarisGameInstanceLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UStanarisGameInstanceLibrary(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "StanarisLibrary", meta = (WorldContext = WorldContextObject))
	static UStanarisGameInstance * GetGameInstance(UObject * WorldContextObject, bool& IsValid);

	UFUNCTION(/*BlueprintCallable, Category = "StanarisLibrary", */meta = (WorldContext = WorldContextObject))
	static UWorld * GetRealWorld(UObject * WorldContextObject);
	
	/*UFUNCTION(BlueprintPure, Category = "StanarisLibrary|DataItems", meta = (WorldContext = WorldContextObject))
	static TArray<FDataItems> GetDataItems(UObject * WorldContextObject, bool& IsValid);*/
	
	/*UFUNCTION(BlueprintPure, Category = "StanarisLibrary|DataItems", meta = (WorldContext = WorldContextObject))
	static FDataItems GetDataItemById(int32 FindId, UObject * WorldContextObject, bool& IsValid);*/

	UFUNCTION(BlueprintPure, Category = "StanarisLibrary|DataItems")
	static ETypeItem DetectTypeItemById(int32 IdItem);

	UFUNCTION(BlueprintPure, Category = "StanarisLibrary|DataItems")
	static void GetItemFromTableById(int32 IdItem, TArray<UDataTable*> Tables, ETypeItem &TypeItem, FEquipItemData &EquipItemData, FUsedItemData &UsedItemData, FQuestItemData &QuestItemData, FCraftItemData &CraftItemData);


private:
	static FEquipItemData FindEquipItemById(UDataTable* EquipTable, int32 IdItem);
	static FCraftItemData FindCraftItemById(UDataTable* CraftTable, int32 IdItem);
	static FUsedItemData FindUsedItemById(UDataTable* UsedTable, int32 IdItem);
	static FQuestItemData FindQuestItemById(UDataTable* QuestTable, int32 IdItem);

};
