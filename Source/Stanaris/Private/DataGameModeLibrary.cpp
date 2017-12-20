// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine.h"

#include "DataGameModeLibrary.h"


UDataGameModeLibrary::UDataGameModeLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

TArray<FEquipment> UDataGameModeLibrary::GetEquipmentItems(class UObject* WorldContextObject, bool & IsValid)
{
	//AStanarisGameMode* GameMode = Cast<AStanarisGameMode>(GEngine->GetWorldFromContextObjectChecked(WorldContextObject));

	return TArray<FEquipment>();
}
