#include "Actions/DoActions/CDoAction_Sniper.h"

#include "Actions/Weapons/CWeapon.h"
#include "Actions/Reload/CReload.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACDoAction_Sniper::ACDoAction_Sniper() {}

void ACDoAction_Sniper::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Sniper]->Weapon;
	Reload = ActionComp->DataAssets[(int8)EActionType::Sniper]->Reload;

	CurrMagazineCount = Datas[0].MaxMagazineCount;
}

void ACDoAction_Sniper::OnAim()
{
}

void ACDoAction_Sniper::OffAim()
{
}