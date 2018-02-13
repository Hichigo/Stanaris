// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/StaticMeshItem.h"
#include "Interfaces/UseItem_Interface.h"
#include "Hero/Components/StatsComp.h"
#include "BaseUsedItem.generated.h"

/**
 * 
 */
UCLASS()
class STANARIS_API ABaseUsedItem : public AStaticMeshItem, public IUseItem_Interface
{
	GENERATED_BODY()

public:
	ABaseUsedItem(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;
	
private:
	UStatsComp* StatsCompRef;
};
