// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
#include "Structures/Inventory/InventoryStructures.h"
#include "Engine/DataTable.h"


#include "StatsComp.generated.h"


USTRUCT(BlueprintType)
struct FDataExp : public FTableRowBase {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Lvl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 ExpToLvl;

	FDataExp()
	{
		Lvl = 0;
		ExpToLvl = 0;
	}
};

USTRUCT(BlueprintType)
struct FBar {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Current;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Max;

	FBar()
	{
		Current = 50.f;
		Max = 100.f;
	}
};

USTRUCT(BlueprintType)
struct FAttributes {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Points;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HealthPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StaminaPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StrengthPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 AgilityPoint;

	FAttributes()
	{
		Points = 0;
		HealthPoint = 10;
		StaminaPoint = 10;
		StrengthPoint = 5;
		AgilityPoint = 5;
	}
};

USTRUCT(BlueprintType)
struct FSecondaryStats {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 HealthK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 StaminaK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RegenHealthPerSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 RegenStaminaPerSec;

	FSecondaryStats()
	{
		HealthK = 40;
		StaminaK = 120;
		RegenHealthPerSec = 1;
		RegenStaminaPerSec = 15;
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
	FAttributes Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FSecondaryStats Secondary;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Defence;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool IsSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CostSprintPerSec;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WalkSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RunSpeed;

	FHeroStats()
	{
		Level = 1;
		Health.Max = Secondary.HealthK * Attributes.HealthPoint;
		Health.Current = Health.Max;
		Stamina.Max = Secondary.StaminaK * Attributes.StaminaPoint;
		Stamina.Current = Stamina.Max;

		Defence = 0;
		Damage = 3;
		IsSprinting = false;
		CostSprintPerSec = 10.f;
		WalkSpeed = 220.f;
		RunSpeed = 600.f;
	}

	FHeroStats& operator+(const FDataItems AddStats)
	{
		Damage += AddStats.Damage;
		Defence += AddStats.Defense;
		
		Health.Max += 0.f;
		Stamina.Max += 0.f;

		Secondary.RegenHealthPerSec += 0;
		Secondary.RegenStaminaPerSec += 0;

		return *this;
	}

	FHeroStats& operator+=(const FDataItems AddStats)
	{
		Damage += AddStats.Damage;
		Defence += AddStats.Defense;

		Health.Max += 0.f;
		Stamina.Max += 0.f;

		Secondary.RegenHealthPerSec += 0;
		Secondary.RegenStaminaPerSec += 0;

		return *this;
	}

	FHeroStats& operator-(const FDataItems AddStats)
	{
		Damage -= AddStats.Damage;
		Defence -= AddStats.Defense;

		Health.Max -= 0.f;
		Stamina.Max -= 0.f;

		Secondary.RegenHealthPerSec -= 0;
		Secondary.RegenStaminaPerSec -= 0;

		return *this;
	}

	FHeroStats& operator-=(const FDataItems AddStats)
	{
		Damage -= AddStats.Damage;
		Defence -= AddStats.Defense;

		Health.Max -= 0.f;
		Stamina.Max -= 0.f;

		Secondary.RegenHealthPerSec -= 0;
		Secondary.RegenStaminaPerSec -= 0;

		return *this;
	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FStatsEvents);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSprintEvents, float, NewSpeed);

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

	
	/* Variable */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stanaris|Stats")
	FHeroStats Stats;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stanaris|Stats")
	UDataTable* ExpTable;

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
	int32 GetAttributePoints();

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
	float GetExpProgress();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	float GetHealthProgress();

	UFUNCTION(BlueprintPure, Category = "Stanaris|Stats")
	float GetStaminaProgress();

	/* All stats functions */
	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats")
	void AddStats(FDataItems AddStats);

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats")
	void SubtractStats(FDataItems SubtractStats);


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

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Stamina|Dispatchers")
	FStatsEvents OnUpdateStamina;

	/* Sprint functions */
	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Stamina|Dispatchers")
	FSprintEvents OnUpdateSpeedCharacter;

	/* Experience functions */
	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Experience")
	void AddExperience(int32 Exp);

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Experience")
	void SubtractExperience(int32 Exp);

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Experience")
	bool OverExperience();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Experience")
	void LevelUp();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Experience")
	void IncreaseExpForNextLevel();

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Experience|Dispatchers")
	FStatsEvents OnUpdateExperience;

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Experience|Dispatchers")
	FStatsEvents OnUpdateLevel;

	/* Attributes functions */
	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Attributes")
	bool DecreasePoint();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Attributes")
	void IncreaseHealhPoint();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Attributes")
	void IncreaseStaminaPoint();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Attributes")
	void IncreaseStrengthPoint();

	UFUNCTION(BlueprintCallable, Category = "Stanaris|Stats|Attributes")
	void IncreaseAgilityPoint();

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Attributes|Dispatchers")
	FStatsEvents OnEmptyAttributePoints;

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Attributes|Dispatchers")
	FStatsEvents OnUpdatePoints;

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Attributes|Dispatchers")
	FStatsEvents OnUpdateHealtsPoints;
	
	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Attributes|Dispatchers")
	FStatsEvents OnUpdateStaminaPoints;

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Attributes|Dispatchers")
	FStatsEvents OnUpdateStrengthPoints;

	UPROPERTY(BlueprintAssignable, Category = "Stanaris|Stats|Attributes|Dispatchers")
	FStatsEvents OnUpdateAgilityPoints;

private:

	UInputComponent* InputComponent;

	void StartSprint();
	void EndSprint();

	/* PRIVATE Health functions */
	void RecalculateHealth();
	
	/* PRIVATE Stamina functions */
	void RecalculateStamina();
};
