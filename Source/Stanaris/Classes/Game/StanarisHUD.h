// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/SMainLayout.h"
#include "Hero/HeroPawn.h"

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

	


	void ShowInventory();
	void HideInventory();

	FORCEINLINE TSharedPtr<class SMainLayout> GetLayoutWidget() const { return LayoutWidget; }

protected:
	UInputComponent* InputComponent = nullptr;

	void ToggleInventory();
	
private:
	AHeroPawn * HeroRef;

	TSharedPtr<class SMainLayout> LayoutWidget; //main layout
};
