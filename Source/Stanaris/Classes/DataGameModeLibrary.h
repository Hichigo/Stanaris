// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "StanarisGameMode.h"

#include "DataGameModeLibrary.generated.h"

/**
 * 
 */
UCLASS()
class STANARIS_API UDataGameModeLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UDataGameModeLibrary(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION(BlueprintPure, Category = "Data Items", meta = (WorldContext = "WorldContextObject"))
	static TArray<FEquipment> GetEquipmentItems(class UObject* WorldContextObject, bool& IsValid);
	
};
