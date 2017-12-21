// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "Runtime/Engine/Classes/Engine/Texture2D.h"

#include "StanarisGameInstance.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ETypeItem : uint8
{
	Equip,
	Used,
	Quest
};

UENUM(BlueprintType)
enum class ETypeEquipment : uint8
{
	FastSlot,
	Weapon,
	Weapon2H,
	Shield,
	Helm,
	Body,
	Pants,
	Boots,
	Gloves,
	Neck,
	Ring
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
struct FDataItems {
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
	UTexture2D *Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh *StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Defense;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIconSize IconSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<int32> TemplateIndexes;

	FDataItems()
	{
		id = -1;

		TypeItem = ETypeItem::Equip;
		TypeEquip = ETypeEquipment::FastSlot;
		Name = FText::FromString(TEXT("none"));
		Description = FText::FromString(TEXT("none"));
		Icon = nullptr;
		StaticMesh = nullptr;
		Defense = -1;
		Damage = -1;
		TemplateIndexes.Add(0);
	}

};

/* Data used items */
//USTRUCT(BlueprintType)
//struct FUsed {
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	int32 id;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	FText Name;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	FText Description;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	UTexture2D *Icon;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	UStaticMesh *StaticMesh;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	FIconSize IconSize;
//};
//
///* Data quest items */
//USTRUCT(BlueprintType)
//struct FQuest {
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	int32 id;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	FText Name;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	FText Description;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	UTexture2D *Icon;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	UStaticMesh *StaticMesh;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite)
//	FIconSize IconSize;
//};

UCLASS(Blueprintable, BlueprintType)
class STANARIS_API UStanarisGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UStanarisGameInstance(const FObjectInitializer& ObjectInitializer);
	
	/* Data Equipment items */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stanaris|DataItems")
	TArray<FDataItems> DataEquipment;

	
};
