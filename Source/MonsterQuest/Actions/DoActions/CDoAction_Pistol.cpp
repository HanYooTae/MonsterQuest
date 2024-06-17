#include "Actions/DoActions/CDoAction_Pistol.h"

#include "Actions/Weapons/CWeapon.h"
#include "Actions/Reload/CReload.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACDoAction_Pistol::ACDoAction_Pistol() {}

void ACDoAction_Pistol::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Pistol]->Weapon;
	Reload = ActionComp->DataAssets[(int8)EActionType::Pistol]->Reload;

	CurrMagazineCount = Datas[0].MaxMagazineCount;
}