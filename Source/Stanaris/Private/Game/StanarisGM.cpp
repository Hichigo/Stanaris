// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/StanarisGM.h"
#include "Game/StanarisHUD.h"
#include "Game/StanarisPC.h"
#include "ConstructorHelpers.h"

AStanarisGM::AStanarisGM(const FObjectInitializer & ObjectInitializer)
	: Super(ObjectInitializer)
{

	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("Blueprint'/Game/Stanaris/Hero/Blueprints/BP_Hero.BP_Hero'"));
	//
	//DefaultPawnClass = PlayerPawnClassFinder.Class;
	HUDClass = AStanarisHUD::StaticClass();
	PlayerControllerClass = AStanarisPC::StaticClass();
}
