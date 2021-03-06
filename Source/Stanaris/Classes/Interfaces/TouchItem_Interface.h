// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TouchItem_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable, MinimalAPI)
class UTouchItem_Interface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class STANARIS_API ITouchItem_Interface
{
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Item Interface")
	FName GetIdItem();
};
