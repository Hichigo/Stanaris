// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Engine/DataTable.h"
#include "Engine/SkeletalMesh.h"

#include "UObject/NoExportTypes.h"
#include "InventoryStructures.generated.h"


/**
*
*/
UENUM(BlueprintType)
enum class ETypeItem : uint8
{
	Equip,
	Used,
	Quest,
	Craft
};


UENUM(BlueprintType)
enum class EWhereItemSlot : uint8
{
	Inventory,
	Equip,
	FastSlot,
	Drag
};


UENUM(BlueprintType)
enum class ETypeEquipment : uint8
{
	Helm,
	Neck,
	Weapon,
	Shield,
	RightRing,
	LeftRing,
	Body,
	Pants,
	Gloves,
	Boots,
	Weapon2H,
	Ring,
	Other,
	FastSlot
};

UENUM(BlueprintType)
enum class ETypeEffectUseItem : uint8
{
	Instant,
	OverTime,
	Temporary
};

USTRUCT(BlueprintType)
struct FIconSize {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Column;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Row;

	FIconSize()
	{
		Column = 1;
		Row = 1;
	}
};

/* Data equipment items*/
USTRUCT(BlueprintType)
struct FDataItems : public FTableRowBase {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETypeItem TypeItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETypeEquipment TypeEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsStackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumberOnStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxNumberOnStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D *Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh *StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIconSize IconSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> TemplateIndexes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass;

	FDataItems()
	{
		id = -1;

		TypeItem = ETypeItem::Equip;
		TypeEquip = ETypeEquipment::FastSlot;
		Name = FText::FromString(TEXT("none"));
		Description = FText::FromString(TEXT("none"));
		IsStackable = false;
		NumberOnStack = 1;
		MaxNumberOnStack = 1;
		Icon = nullptr;
		StaticMesh = nullptr;
		SkeletalMesh = nullptr;
		Defense = -1;
		Damage = -1;
		TemplateIndexes.Add(0);
		ItemClass = nullptr;
	}
};


USTRUCT(BlueprintType)
struct FInventoryItem {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumberOfItems;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETypeItem TypeItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor *ItemRef;

	FInventoryItem()
	{
		id = -1;
		NumberOfItems = 1;
		TypeItem = ETypeItem::Equip;
		ItemRef = nullptr;
	}


};

USTRUCT(BlueprintType)
struct FMasterItemData : public FTableRowBase {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETypeItem TypeItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsStackable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumberOfStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxNumberOfStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D *Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh *StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIconSize IconSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> TemplateIndexes;

	FMasterItemData()
	{
		id = -1;
		TypeItem = ETypeItem::Craft;
		Name = FText::FromString(TEXT("none"));
		Description = FText::FromString(TEXT("none"));
		IsStackable = false;
		NumberOfStack = 1;
		MaxNumberOfStack = 1;
		Icon = nullptr;
		StaticMesh = nullptr;
		TemplateIndexes.Add(0);
	}
};


USTRUCT(BlueprintType)
struct FEquipItemData : public FMasterItemData {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETypeEquipment TypeEquip;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMesh* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Defence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;

	FEquipItemData()
	{
		TypeEquip = ETypeEquipment::Other;
		SkeletalMesh = nullptr;
		Defence = 0;
		Damage = 0;
	}
};

USTRUCT(BlueprintType)
struct FCraftItemData : public FMasterItemData {
	GENERATED_USTRUCT_BODY()


	FCraftItemData()
	{

	}
};

USTRUCT(BlueprintType)
struct FUsedItemData : public FMasterItemData {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETypeEquipment TypeEquip;

	FUsedItemData()
	{
		TypeEquip = ETypeEquipment::FastSlot;
	}
};

USTRUCT(BlueprintType)
struct FQuestItemData : public FMasterItemData {
	GENERATED_USTRUCT_BODY()

	FQuestItemData()
	{

	}
};

UCLASS()
class STANARIS_API UInventoryStructures : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
