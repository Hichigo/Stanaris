// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "StanarisGameInstance.h"

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
	
	UFUNCTION(BlueprintPure, Category = "StanarisLibrary|DataItems", meta = (WorldContext = WorldContextObject))
	static TArray<FDataItems> GetDataItems(UObject * WorldContextObject, bool& IsValid);
	
};
