#include "Actions/DoActions/CDoAction_Rifle.h"

#include "Actions/Weapons/CWeapon.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACDoAction_Rifle::ACDoAction_Rifle() {}

void ACDoAction_Rifle::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Rifle]->Weapon;
}