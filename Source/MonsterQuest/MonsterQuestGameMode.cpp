#include "MonsterQuestGameMode.h"
#include "CPlayer/CPlayer.h"
#include "UObject/ConstructorHelpers.h"

AMonsterQuestGameMode::AMonsterQuestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/Characters/Player/BP_CPlayer.BP_CPlayer_C'"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
