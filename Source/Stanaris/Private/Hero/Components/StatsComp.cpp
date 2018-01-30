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
		if (Stats.RegenHealthPerSec > 0)
		{
			float RegenPerTick = Stats.RegenHealthPerSec * DeltaTime;
			AddHealth(RegenPerTick);
		}
	}
	/* regen healt finish */

	/* regen stamina start */
	if (Stats.Stamina.Current < Stats.Stamina.Max)
	{
		if (Stats.RegenStaminaPerSec > 0)
		{
			float RegenPerTick = Stats.RegenStaminaPerSec * DeltaTime;
			AddStamina(RegenPerTick);
		}
	}
	/* regen stamina finish */
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

int32 UStatsComp::GetRegenHealth()
{
	return Stats.RegenHealthPerSec;
}

int32 UStatsComp::GetRegenStamina()
{
	return Stats.RegenStaminaPerSec;
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

FText UStatsComp::GetStaminaText()
{
	FFormatNamedArguments Arguments;

	int32 Current = (int32)Stats.Stamina.Current;
	Arguments.Add(TEXT("CurrentStamina"), FText::AsNumber(Current));
	Arguments.Add(TEXT("MaxStamina"), FText::AsNumber(Stats.Stamina.Max));

	return FText::Format(LOCTEXT("HUDStaminaText", "{CurrentStamina} / {MaxStamina}"), Arguments);
}

float UStatsComp::GetHealthProgress()
{
	return Stats.Health.Current / Stats.Health.Max;
}

float UStatsComp::GetStaminaProgress()
{
	return Stats.Stamina.Current / Stats.Stamina.Max;
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

bool UStatsComp::LessZeroStamina()
{
	return Stats.Stamina.Current < 0;
}

bool UStatsComp::OverStamina()
{
	return Stats.Stamina.Current > Stats.Health.Max;
}

bool UStatsComp::CheckStaminaOnAction(float Stamina)
{
	return Stats.Stamina.Current > Stamina;
}

void UStatsComp::SetFullStamina()
{
	Stats.Stamina.Current = Stats.Health.Max;
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
	}

	OnUpdateStamina.Broadcast();
}

void UStatsComp::StartSprint()
{
	OnUpdateSpeedCharacter.Broadcast(Stats.RunSpeed);
}

void UStatsComp::EndSprint()
{
	OnUpdateSpeedCharacter.Broadcast(Stats.WalkSpeed);
}

#undef LOCTEXT_NAMESPACE 