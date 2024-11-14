// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiplayerCourseUE5GameMode.h"
#include "MultiplayerCourseUE5Character.h"
#include "UObject/ConstructorHelpers.h"

AMultiplayerCourseUE5GameMode::AMultiplayerCourseUE5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
