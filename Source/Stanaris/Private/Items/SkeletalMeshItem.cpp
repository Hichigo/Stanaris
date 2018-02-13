// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/SkeletalMeshItem.h"



ASkeletalMeshItem::ASkeletalMeshItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SkeletalItem = ObjectInitializer.CreateAbstractDefaultSubobject<USkeletalMeshComponent>(this, TEXT("ItemMesh"));

	SkeletalItem->SetCollisionObjectType(ECC_PhysicsBody);
	SkeletalItem->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SkeletalItem->SetCollisionResponseToAllChannels(ECR_Block);
	SkeletalItem->SetSimulatePhysics(true);

	RootComponent = SkeletalItem;

}

void ASkeletalMeshItem::OnConstruction(const FTransform & Transform)
{
	Super::OnConstruction(Transform);

	SkeletalItem->SetSkeletalMesh(Data.SkeletalMesh);
}
