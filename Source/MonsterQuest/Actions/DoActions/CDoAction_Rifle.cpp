#include "Actions/DoActions/CDoAction_Rifle.h"

#include "Actions/Weapons/CWeapon.h"
#include "Actions/Reload/CReload.h"
#include "Actions/Aim/CAim_Rifle.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACDoAction_Rifle::ACDoAction_Rifle() {}

void ACDoAction_Rifle::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Rifle]->Weapon;
	Reload = ActionComp->DataAssets[(int8)EActionType::Rifle]->Reload;
	
	CurrMagazineCount = Datas[0].MaxMagazineCount;
}

void ACDoAction_Rifle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}