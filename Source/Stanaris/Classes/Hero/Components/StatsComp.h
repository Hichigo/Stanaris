// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Structures/Inventory/InventoryStructures.h"

#include "StatsComp.generated.h"


USTRUCT(BlueprintType)
struct FBar {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Current;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Max;

	FBar()
	{
		Current = 100.f;
		Max = 100.f;
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
	FBar Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RegenHealthPerSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RegenStaminaPerSec;

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
		RegenStaminaPerSec = 15;
	}

	FHeroStats& operator+(const FEquipItemData AddStats)
	{
		Damage += AddStats.Damage;
		Defence += AddStats.Defence;
		
		Health.Max += 0.f;
		Stamina.Max += 0.f;

		RegenHealthPerSec += 0;
		RegenStaminaPerSec += 0;

		return *this;
	}

	FHeroStats& operator+=(const FEquipItemData AddStats)
	{
		Damage += AddStats.Damage;
		Defence += AddStats.Defence;

		Health.Max += 0.f;
		Stamina.Max += 0.f;

		RegenHealthPerSec += 0;
		RegenStaminaPerSec += 0;

		return *this;
	}

	FHeroStats& operator-(const FEquipItemData AddStats)
	{
		Damage -= AddStats.Damage;
		Defence -= AddStats.Defence;

		Health.Max -= 0.f;
		Stamina.Max -= 0.f;

		RegenHealthPerSec -= 0;
		RegenStaminaPerSec -= 0;

		return *this;
	}

	FHeroStats& operator-=(const FEquipItemData AddStats)
	{
		Damage -= AddStats.Damage;
		Defence -= AddStats.Defence;

		Health.Max -= 0.f;
		Stamina.Max -= 0.f;

		RegenHealthPerSec -= 0;
		RegenStaminaPerSec -= 0;

		return *this;
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStatsEvents);

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
	FBar GetExp();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	FBar GetHealth();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	FBar GetStamina();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetRegenHealth();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetRegenStamina();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetDamage();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	int32 GetDefence();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	FText GetExpText();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	FText GetHealthText();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	FText GetStaminaText();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	float GetHealthProgress();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	float GetStaminaProgress();


	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats")
	void AddStats(FEquipItemData AddStats);

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats")
	void SubtractStats(FEquipItemData SubtractStats);


	/* Health functions */
	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Health")
	bool IsDeath();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Health")
	bool OverHealth();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Health")
	void SetFullHealth();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Health")
	void AddHealth(float Health);

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Health")
	void SubtractHealth(float Health);

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Health|Dispatchers")
	FStatsEvents OnUpdateHealth;

	/* Stamina functions */
	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Stamina")
	bool LessZeroStamina();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Stamina")
	bool OverStamina();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Stamina")
	bool CheckStaminaOnAction(float Stamina);

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Stamina")
	void SetFullStamina();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Stamina")
	void AddStamina(float Stamina);

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Stamina")
	void SubtractStamina(float Stamina);

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Health|Dispatchers")
	FStatsEvents OnUpdateStamina;
};
