// Copyright Epic Games, Inc. All Rights Reserved.

#include "A1UGameMode.h"
#include "A1UCharacter.h"
#include "UObject/ConstructorHelpers.h"

AA1UGameMode::AA1UGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
