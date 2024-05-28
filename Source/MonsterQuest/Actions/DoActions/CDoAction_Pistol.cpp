#include "Actions/DoActions/CDoAction_Pistol.h"

#include "Actions/Weapons/CWeapon.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACDoAction_Pistol::ACDoAction_Pistol() {}

void ACDoAction_Pistol::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Pistol]->Weapon;
}