// Fill out your copyright notice in the Description page of Project Settings.

#include "Game/StanarisGM.h"
#include "Game/StanarisHUD.h"
#include "Game/StanarisPC.h"

AStanarisGM::AStanarisGM(const FObjectInitializer & ObjectInitializer)
	: Super(ObjectInitializer)
{
	HUDClass = AStanarisHUD::StaticClass();
	PlayerControllerClass = AStanarisPC::StaticClass();
}
