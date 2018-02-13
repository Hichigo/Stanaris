// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/BaseUsedItem.h"



ABaseUsedItem::ABaseUsedItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void ABaseUsedItem::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseUsedItem::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);

}
