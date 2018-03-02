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
		SAssignNew(Layout, SMainLayout).HUD(this); // (this set variable) add the widget and assign it to the var
		GEngine->
			GameViewport->
				AddViewportWidgetContent(SNew(SWeakWidget)
					.PossiblyNullContent(Layout.ToSharedRef()));

		Layout.Get()->SetVisibility(EVisibility::Hidden);
	}
	
	
}

void AStanarisHUD::BeginPlay()
{
	Super::BeginPlay();

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent)
	{
		InputComponent->BindAction("Inventory", IE_Pressed, this, &AStanarisHUD::ToggleInventory);
	}

}

void AStanarisHUD::ToggleInventory()
{
	if (Layout.Get()->GetVisibility() == EVisibility::Hidden)
	{
		ShowInventory();
	}
	else {
		HideInventory();
	}
}

void AStanarisHUD::ShowInventory()
{
	Layout.Get()->SetVisibility(EVisibility::Visible);

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameAndUI());
}

void AStanarisHUD::HideInventory()
{
	Layout.Get()->SetVisibility(EVisibility::Hidden);

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
}
