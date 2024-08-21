#include "CEnemy/CEnemy_Boss.h"

#include "CPlayer/CPlayer.h"
#include "Widgets/Menu/CClear.h"
#include "GameFramework/Controller.h"

#include "Global.h"

ACEnemy_Boss::ACEnemy_Boss() {}

void ACEnemy_Boss::BeginPlay()
{
	Super::BeginPlay();
}

void ACEnemy_Boss::End_Dead()
{
	Super::End_Dead();

	Boss_Dead();
}

void ACEnemy_Boss::Boss_Dead()
{
	APlayerController* controller = GetWorld()->GetFirstPlayerController();
	CheckNull(controller);
	controller->bShowMouseCursor = true;

	ACPlayer* player = Cast<ACPlayer>(controller->GetCharacter());
	CheckNull(player);
	player->ClearWidget->Attach();
	player->ClearWidget->SetVisibility(ESlateVisibility::Visible);
}