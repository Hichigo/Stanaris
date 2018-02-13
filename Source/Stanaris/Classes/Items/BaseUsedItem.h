// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/StaticMeshItem.h"
#include "BaseUsedItem.generated.h"

/**
 * 
 */
UCLASS()
class STANARIS_API ABaseUsedItem : public AStaticMeshItem
{
	GENERATED_BODY()

public:
	ABaseUsedItem(const FObjectInitializer& ObjectInitializer);
	
	
};
