// Fill out your copyright notice in the Description page of Project Settings.

#include "Hero/Components/StatsComp.h"


#define LOCTEXT_NAMESPACE "HUD" 
// Sets default values for this component's properties
UStatsComp::UStatsComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatsComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatsComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (Stats.Health.Current < Stats.Health.Max)
	{
		if (Stats.RegenHealthPerSec > 0)
		{
			float RegenPerTick = Stats.RegenHealthPerSec * DeltaTime;
			AddHealth(RegenPerTick);
		}
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

FBar UStatsComp::GetEndurance()
{
	return Stats.Endurance;
}

int32 UStatsComp::GetRegenHealth()
{
	return Stats.RegenHealthPerSec;
}

int32 UStatsComp::GetRegenEndurance()
{
	return Stats.RegenEndurancePerSec;
}

int32 UStatsComp::GetDamage()
{
	return Stats.Damage;
}

int32 UStatsComp::GetDefence()
{
	return Stats.Defence;
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

FText UStatsComp::GetEnduranceText()
{
	FFormatNamedArguments Arguments;

	int32 Current = (int32)Stats.Endurance.Current;
	Arguments.Add(TEXT("CurrentEndurance"), FText::AsNumber(Current));
	Arguments.Add(TEXT("MaxEndurance"), FText::AsNumber(Stats.Endurance.Max));

	return FText::Format(LOCTEXT("HUDEnduranceText", "{CurrentEndurance} / {MaxEndurance}"), Arguments);
}

float UStatsComp::GetHealthProgress()
{
	return Stats.Health.Current / Stats.Health.Max;
}

float UStatsComp::GetEnduranceProgress()
{
	return Stats.Endurance.Current / Stats.Endurance.Max;
}

void UStatsComp::AddStats(FEquipItemData AddStats)
{
	Stats += AddStats;
}

void UStatsComp::SubtractStats(FEquipItemData SubtractStats)
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

#undef LOCTEXT_NAMESPACE 