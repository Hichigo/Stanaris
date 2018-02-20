// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Stanaris.h"
#include "Modules/ModuleManager.h"
#include "UI/Style/InventoryStyle.h"

class FSlateTutorialsGameModule : public FDefaultGameModuleImpl
{
	// Called whenever the module is starting up. In here, we unregister any style sets 
	// (which may have been added by other modules) sharing our 
	// style set's name, then initialize our style set. 
	virtual void StartupModule() override
	{
		//Hot reload hack
		FSlateStyleRegistry::UnRegisterSlateStyle(FInventoryStyle::GetStyleSetName());
		FInventoryStyle::Initialize();
	}

	// Called whenever the module is shutting down. Here, we simply tell our MenuStyles to shut down.
	virtual void ShutdownModule() override
	{
		FInventoryStyle::Shutdown();
	}

};

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, Stanaris, "Stanaris" );
 