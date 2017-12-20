// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "StanarisGameMode.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ETypeItems : uint8
{
	Equip,
	Use,
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
};

/* Data equipment items*/
USTRUCT(BlueprintType)
struct FEquipment {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 id;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ETypeEquipment Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D *Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMesh *StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Defence;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIconSize IconSize;
};

UCLASS(Blueprintable, BlueprintType)
class STANARIS_API AStanarisGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AStanarisGameMode(const FObjectInitializer& ObjectInitializer);
	
	/* Data Equipment items */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Items")
	TArray<FEquipment> DataEquipment;
	
};
