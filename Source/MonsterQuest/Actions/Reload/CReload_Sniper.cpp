#include "Actions/Reload/CReload_Sniper.h"

#include "Actions/Weapons/CWeapon.h"
#include "Actions/DoActions/CDoAction.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACReload_Sniper::ACReload_Sniper() {}

void ACReload_Sniper::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Sniper]->Weapon;
	DoAction = ActionComp->DataAssets[(int8)EActionType::Sniper]->DoAction;
}