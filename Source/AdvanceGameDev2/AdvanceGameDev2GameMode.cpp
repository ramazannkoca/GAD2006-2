// Copyright Epic Games, Inc. All Rights Reserved.

#include "AdvanceGameDev2GameMode.h"
#include "AdvanceGameDev2Character.h"
#include "UObject/ConstructorHelpers.h"

AAdvanceGameDev2GameMode::AAdvanceGameDev2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
