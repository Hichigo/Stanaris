// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/StaticMeshItem.h"



AStaticMeshItem::AStaticMeshItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	StaticItem = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("ItemMesh"));
	StaticItem->SetCollisionObjectType(ECC_PhysicsBody);
	StaticItem->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	StaticItem->SetCollisionResponseToAllChannels(ECR_Block);
	StaticItem->SetSimulatePhysics(true);

	RootComponent = StaticItem;
}

void AStaticMeshItem::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);

	StaticItem->SetStaticMesh(Data.StaticMesh);
}
