#include "Actions/Reload/CReload_Rifle.h"

#include "Actions/Weapons/CWeapon.h"
#include "Actions/DoActions/CDoAction.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACReload_Rifle::ACReload_Rifle() {}

void ACReload_Rifle::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Rifle]->Weapon;
	DoAction = ActionComp->DataAssets[(int8)EActionType::Rifle]->DoAction;
}