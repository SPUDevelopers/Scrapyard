// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Scrapyard.h"
#include "ScrapyardGameMode.h"
#include "ScrapyardHUD.h"
#include "ScrapyardCharacter.h"

AScrapyardGameMode::AScrapyardGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AScrapyardHUD::StaticClass();
}
