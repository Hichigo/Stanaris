// Fill out your copyright notice in the Description page of Project Settings.

#include "Hero/Components/StatsComp.h"


#define LOCTEXT_NAMESPACE "HUD" 
// Sets default values for this component's properties
UStatsComp::UStatsComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	InputComponent = nullptr;
	
	// ...
}


// Called when the game starts
void UStatsComp::BeginPlay()
{
	Super::BeginPlay();

	/// set character walk speed
	OnUpdateSpeedCharacter.Broadcast(Stats.WalkSpeed);
	IncreaseExpForNextLevel(); // set experience to first level

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent)
	{
		InputComponent->BindAction("Sprint", IE_Pressed, this, &UStatsComp::StartSprint);
		InputComponent->BindAction("Sprint", IE_Released, this, &UStatsComp::EndSprint);
	}
	// ...
	
}


// Called every frame
void UStatsComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	/* regen health start */
	if (Stats.Health.Current < Stats.Health.Max)
	{
		if (Stats.Secondary.RegenHealthPerSec > 0)
		{
			float RegenPerTick = Stats.Secondary.RegenHealthPerSec * DeltaTime;
			AddHealth(RegenPerTick);
		}
	}
	/* regen healt finish */

	/* regen stamina start */
	if (Stats.Stamina.Current < Stats.Stamina.Max)
	{
		if (Stats.Secondary.RegenStaminaPerSec > 0 && !Stats.IsSprinting)
		{
			float RegenPerTick = Stats.Secondary.RegenStaminaPerSec * DeltaTime;
			AddStamina(RegenPerTick);
		}
	}
	/* regen stamina finish */

	/* Sprint cost */
	if (Stats.IsSprinting)
	{
		float CostPerTick = Stats.CostSprintPerSec * DeltaTime;
		SubtractStamina(CostPerTick);
	}
}

int32 UStatsComp::GetLevel()
{
	return Stats.Level;
}

FBar UStatsComp::GetExp()
{
	return Stats.Experience;
}

FBar UStatsComp::GetHealth()
{
	return Stats.Health;
}

FBar UStatsComp::GetStamina()
{
	return Stats.Stamina;
}

int32 UStatsComp::GetHealthMax()
{
	return Stats.Health.Max;
}

int32 UStatsComp::GetStaminaMax()
{
	return Stats.Stamina.Max;
}

int32 UStatsComp::GetRegenHealth()
{
	return Stats.Secondary.RegenHealthPerSec;
}

int32 UStatsComp::GetRegenStamina()
{
	return Stats.Secondary.RegenStaminaPerSec;
}

int32 UStatsComp::GetAttributePoints()
{
	return Stats.Attributes.Points;
}

int32 UStatsComp::GetHealthPoint()
{
	return Stats.Attributes.HealthPoint;
}

int32 UStatsComp::GetStaminaPoint()
{
	return Stats.Attributes.StaminaPoint;
}

int32 UStatsComp::GetStrengthPoint()
{
	return Stats.Attributes.StrengthPoint;
}

int32 UStatsComp::GetAgilityPoint()
{
	return Stats.Attributes.AgilityPoint;
}

int32 UStatsComp::GetDamage()
{
	return Stats.Damage;
}

int32 UStatsComp::GetDefense()
{
	return Stats.Defense;
}

FText UStatsComp::GetExpText()
{
	FFormatNamedArguments Arguments;

	int32 Current = (int32)Stats.Experience.Current;
	Arguments.Add(TEXT("CurrentExp"), FText::AsNumber(Current));
	Arguments.Add(TEXT("MaxExp"), FText::AsNumber(Stats.Experience.Max));

	return FText::Format(LOCTEXT("HUDExpText", "{CurrentExp} / {MaxExp}"), Arguments);
}

FText UStatsComp::GetHealthText()
{
	FFormatNamedArguments Arguments;

	int32 Current = (int32)Stats.Health.Current;
	Arguments.Add(TEXT("CurrentHealth"), FText::AsNumber(Current));
	Arguments.Add(TEXT("MaxHealth"), FText::AsNumber(Stats.Health.Max));

	return FText::Format(LOCTEXT("HUDHealhtText", "{CurrentHealth} / {MaxHealth}"), Arguments);
}

FText UStatsComp::GetStaminaText()
{
	FFormatNamedArguments Arguments;

	int32 Current = (int32)Stats.Stamina.Current;
	Arguments.Add(TEXT("CurrentStamina"), FText::AsNumber(Current));
	Arguments.Add(TEXT("MaxStamina"), FText::AsNumber(Stats.Stamina.Max));

	return FText::Format(LOCTEXT("HUDStaminaText", "{CurrentStamina} / {MaxStamina}"), Arguments);
}

float UStatsComp::GetExpProgress()
{
	return (float)Stats.Experience.Current / (float)Stats.Experience.Max;
}

float UStatsComp::GetHealthProgress()
{
	return Stats.Health.Current / Stats.Health.Max;
}

float UStatsComp::GetStaminaProgress()
{
	return Stats.Stamina.Current / Stats.Stamina.Max;
}

void UStatsComp::AddStats(FDataItems AddStats)
{
	Stats += AddStats;
}

void UStatsComp::SubtractStats(FDataItems SubtractStats)
{
	Stats -= SubtractStats;
}

bool UStatsComp::IsDeath()
{
	return Stats.Health.Current <= 0;
}

bool UStatsComp::OverHealth()
{
	return Stats.Health.Current > Stats.Health.Max;
}

void UStatsComp::SetFullHealth()
{
	Stats.Health.Current = Stats.Health.Max;
}

void UStatsComp::AddHealth(float Health)
{
	Stats.Health.Current += Health;
	
	if (OverHealth())
	{
		SetFullHealth();
	}

	OnUpdateHealth.Broadcast();
}

void UStatsComp::SubtractHealth(float Health)
{
	Stats.Health.Current -= Health;
	
	if (Stats.Health.Current < 0)
	{
		Stats.Health.Current = 0;
	}

	OnUpdateHealth.Broadcast();
}

bool UStatsComp::LessZeroStamina()
{
	return Stats.Stamina.Current < 0;
}

bool UStatsComp::OverStamina()
{
	return Stats.Stamina.Current > Stats.Stamina.Max;
}

bool UStatsComp::CheckStaminaOnAction(float Stamina)
{
	return Stats.Stamina.Current > Stamina;
}

void UStatsComp::SetFullStamina()
{
	Stats.Stamina.Current = Stats.Stamina.Max;
}

void UStatsComp::AddStamina(float Stamina)
{
	Stats.Stamina.Current += Stamina;

	if (OverStamina())
	{
		SetFullStamina();
	}
	
	OnUpdateStamina.Broadcast();
}

void UStatsComp::SubtractStamina(float Stamina)
{
	Stats.Stamina.Current -= Stamina;

	if (LessZeroStamina())
	{
		Stats.Stamina.Current = 0;
		EndSprint();
	}

	OnUpdateStamina.Broadcast();
}

void UStatsComp::AddExperience(int32 Exp)
{
	Stats.Experience.Current += Exp;

	if (OverExperience())
	{
		Stats.Experience.Current -= Stats.Experience.Max;
		LevelUp();
		///increase Stats.Experience.Max
		IncreaseExpForNextLevel();
	}

	OnUpdateExperience.Broadcast();
}

void UStatsComp::SubtractExperience(int32 Exp)
{
	Stats.Experience.Current -= Exp;
	OnUpdateExperience.Broadcast();
}

bool UStatsComp::OverExperience()
{
	return Stats.Experience.Current >= Stats.Experience.Max;
}

void UStatsComp::LevelUp()
{
	Stats.Level += 1;
	Stats.Attributes.Points += 3;
	OnUpdateLevel.Broadcast();
	OnUpdatePoints.Broadcast();
}

void UStatsComp::IncreaseExpForNextLevel()
{
	// get exp for next level from data table
	FString ContextString; //error or warning
	
	FName RowName = FName(*FString::FromInt(Stats.Level));

	FDataExp *row = nullptr;

	if (ExpTable)
	{
		row = ExpTable->FindRow<FDataExp>(RowName, ContextString);
	}

	if (row)
	{
		Stats.Experience.Max = row->ExpToLvl;
		OnUpdateExperience.Broadcast();
	}
}

bool UStatsComp::DecreasePoint()
{
	if (Stats.Attributes.Points > 0)
	{
		Stats.Attributes.Points -= 1;

		if (Stats.Attributes.Points == 0)
		{
			OnEmptyAttributePoints.Broadcast();
		}

		OnUpdatePoints.Broadcast();
		return true;
	}
	return false;
}

void UStatsComp::IncreaseHealthPoint()
{
	if (DecreasePoint())
	{
		Stats.Attributes.HealthPoint += 1;
		RecalculateHealth();
		OnUpdateHealthPoints.Broadcast();
	}
}

void UStatsComp::IncreaseStaminaPoint()
{
	if (DecreasePoint())
	{
		Stats.Attributes.StaminaPoint += 1;
		RecalculateStamina();
		OnUpdateStaminaPoints.Broadcast();
	}
}

void UStatsComp::IncreaseStrengthPoint()
{
	if (DecreasePoint())
	{
		Stats.Attributes.StrengthPoint += 1;

		OnUpdateStrengthPoints.Broadcast();
	}
}

void UStatsComp::IncreaseAgilityPoint()
{
	if (DecreasePoint())
	{
		Stats.Attributes.AgilityPoint += 1;

		OnUpdateAgilityPoints.Broadcast();
	}
}

void UStatsComp::StartSprint()
{
	Stats.IsSprinting = true;
	OnUpdateSpeedCharacter.Broadcast(Stats.RunSpeed);
}

void UStatsComp::EndSprint()
{
	Stats.IsSprinting = false;
	OnUpdateSpeedCharacter.Broadcast(Stats.WalkSpeed);
}

void UStatsComp::RecalculateHealth()
{
	Stats.Health.Max = Stats.Secondary.HealthK * Stats.Attributes.HealthPoint;
	OnUpdateHealth.Broadcast();
}

void UStatsComp::RecalculateStamina()
{
	Stats.Stamina.Max = Stats.Secondary.StaminaK * Stats.Attributes.StaminaPoint;
	OnUpdateStamina.Broadcast();
}

#undef LOCTEXT_NAMESPACE 