// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "StanarisGameInstance.generated.h"

/**
 * 
 */

UCLASS(Blueprintable, BlueprintType)
class STANARIS_API UStanarisGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UStanarisGameInstance(const FObjectInitializer& ObjectInitializer);
	
	
};
