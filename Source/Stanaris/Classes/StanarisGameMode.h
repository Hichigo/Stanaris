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
	float Column;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Row;
};

UCLASS()
class STANARIS_API AStanarisGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
	
	
	
};
