// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/TouchItem_Interface.h"
#include "BaseItem.generated.h"

UCLASS()
class STANARIS_API ABaseItem : public AActor, public ITouchItem_Interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	virtual FName GetIdItem_Implementation() override;
};
