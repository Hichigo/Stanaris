// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatsComp.generated.h"


USTRUCT(BlueprintType)
struct FBar {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Current;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Max;

	FBar()
	{
		Current = 100;
		Max = 100;
	}
};

USTRUCT(BlueprintType)
struct FHeroStats {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBar Experience;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBar Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBar Endurance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RegenHealthPerSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RegenEndurancePerSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Defence;

	FHeroStats()
	{
		Level = 1;
		Defence = 0;
		Damage = 3;
		RegenHealthPerSec = 0;
		RegenEndurancePerSec = 15;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STANARIS_API UStatsComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatsComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stanaris|Stats")
	FHeroStats Stats;


	/* GETTERS */
	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetLevel();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	FBar GexExp();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	FBar GexHealth();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	FBar GexEndurance();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetRegenHealth();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetRegenEndurance();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetDamage();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetDefence();

};
