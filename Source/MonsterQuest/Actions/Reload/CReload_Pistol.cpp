#include "Actions/Reload/CReload_Pistol.h"

#include "Actions/Weapons/CWeapon.h"

#include "Actions/Weapons/CWeapon.h"
#include "Actions/DoActions/CDoAction.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACReload_Pistol::ACReload_Pistol() {}

void ACReload_Pistol::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Pistol]->Weapon;
	DoAction = ActionComp->DataAssets[(int8)EActionType::Pistol]->DoAction;
}