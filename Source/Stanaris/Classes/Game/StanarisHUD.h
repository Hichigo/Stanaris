// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/SMainLayout.h"
#include "StanarisHUD.generated.h"

/**
 * 
 */
UCLASS()
class STANARIS_API AStanarisHUD : public AHUD
{
	GENERATED_BODY()

public:
	AStanarisHUD(const FObjectInitializer &ObjectInitializer);
	

	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	TSharedPtr<class SMainLayout> Layout; //main layout


	void ShowInventory();
	void HideInventory();

protected:
	UInputComponent* InputComponent = nullptr;

	void ToggleInventory();
	
};
