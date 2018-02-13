// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/BaseItem.h"
#include "Components/StaticMeshComponent.h"
#include "StaticMeshItem.generated.h"

/**
 * 
 */
UCLASS()
class STANARIS_API AStaticMeshItem : public ABaseItem
{
	GENERATED_BODY()

public:
	AStaticMeshItem(const FObjectInitializer& ObjectInitializer);

	virtual void OnConstruction(const FTransform& Transform) override;
	
private:

	UPROPERTY(VisibleAnywhere, Category = "Item")
	UStaticMeshComponent* StaticItem;
	

};
