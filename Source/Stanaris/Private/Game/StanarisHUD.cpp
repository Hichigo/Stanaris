// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/StanarisHUD.h"
#include "Engine.h"


AStanarisHUD::AStanarisHUD(const FObjectInitializer & ObjectInitializer)
	: Super(ObjectInitializer)
{
	HeroRef = nullptr;
}

void AStanarisHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	

	

	if (GEngine && GEngine->GameViewport) // make sure our screen is ready for the widget
	{
		//GridInventoryWidget->SetTest(1);
		SAssignNew(LayoutWidget, SMainLayout).HUD(this); // (this set variable) add the widget and assign it to the var
		GEngine->
			GameViewport->
				AddViewportWidgetContent(SNew(SWeakWidget)
					.PossiblyNullContent(LayoutWidget.ToSharedRef()));

		LayoutWidget.Get()->SetVisibility(EVisibility::Hidden);
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
	
	HeroRef = Cast<AHeroPawn>(GetOwningPawn());

	if (HeroRef != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hero not null"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Hero null"));
	}

}

void AStanarisHUD::ToggleInventory()
{
	if (LayoutWidget.Get()->GetVisibility() == EVisibility::Hidden)
	{
		ShowInventory();
	}
	else {
		HideInventory();
	}
}

void AStanarisHUD::ShowInventory()
{
	LayoutWidget.Get()->SetVisibility(EVisibility::Visible);

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameAndUI());
}

void AStanarisHUD::HideInventory()
{
	LayoutWidget.Get()->SetVisibility(EVisibility::Hidden);

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
}
