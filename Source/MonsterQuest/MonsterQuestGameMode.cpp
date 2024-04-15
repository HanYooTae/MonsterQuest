// Copyright Epic Games, Inc. All Rights Reserved.

#include "MonsterQuestGameMode.h"
#include "CPlayer/CPlayer.h"
#include "UObject/ConstructorHelpers.h"

AMonsterQuestGameMode::AMonsterQuestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
