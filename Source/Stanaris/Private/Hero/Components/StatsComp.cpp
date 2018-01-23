// Fill out your copyright notice in the Description page of Project Settings.

#include "Hero/Components/StatsComp.h"



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

	// ...
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

void UStatsComp::AddStats(FEquipItemData AddStats)
{
	Stats += AddStats;
}

void UStatsComp::SubtractStats(FEquipItemData SubtractStats)
{
	Stats -= SubtractStats;
}

