// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Inventory/SInventory.h"
#include "StanarisHUD.generated.h"

/**
 * 
 */
UCLASS()
class STANARIS_API AStanarisHUD : public AHUD
{
	GENERATED_BODY()


	AStanarisHUD(const FObjectInitializer &ObjectInitializer);
	

	virtual void PostInitializeComponents() override;

	TSharedPtr<class SInventory> TestSlotWidget;
};
