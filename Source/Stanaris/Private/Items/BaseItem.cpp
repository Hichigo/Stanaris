// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/BaseItem.h"
#include "UObject/ConstructorHelpers.h"


// Sets default values
ABaseItem::ABaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set data table from content editor
	ConstructorHelpers::FObjectFinder<UDataTable> ItemsTable_BP(TEXT("DataTable'/Game/Stanaris/DataTable/StanarisItems_All.StanarisItems_All'"));
	ItemsTable = ItemsTable_BP.Object;
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FName ABaseItem::GetIdItem_Implementation()
{
	return IdItem;
}

