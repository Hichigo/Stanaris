// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/StanarisHUD.h"
#include "Engine.h"

AStanarisHUD::AStanarisHUD(const FObjectInitializer & ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void AStanarisHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	
	if (GEngine && GEngine->GameViewport) // make sure our screen is ready for the widget
	{
		//GridInventoryWidget->SetTest(1);
		SAssignNew(TestSlotWidget, SGridInventory); // (this set variable) add the widget and assign it to the var
		GEngine->
			GameViewport->
				AddViewportWidgetContent(SNew(SWeakWidget)
					.PossiblyNullContent(TestSlotWidget.ToSharedRef()));
	}
	
}
