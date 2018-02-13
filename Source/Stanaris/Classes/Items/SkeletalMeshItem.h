// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/BaseItem.h"
#include "Components/SkeletalMeshComponent.h"
#include "SkeletalMeshItem.generated.h"

/**
 * 
 */
UCLASS()
class STANARIS_API ASkeletalMeshItem : public ABaseItem
{
	GENERATED_BODY()
	
	
public:
	ASkeletalMeshItem(const FObjectInitializer& ObjectInitializer);

	virtual void OnConstruction(const FTransform& Transform) override;
	
private:
	UPROPERTY(VisibleAnywhere, Category = "Item")
	USkeletalMeshComponent* SkeletalItem;
	
};
