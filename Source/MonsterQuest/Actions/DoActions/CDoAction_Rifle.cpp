#include "Actions/DoActions/CDoAction_Rifle.h"

#include "Actions/Weapons/CWeapon.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACDoAction_Rifle::ACDoAction_Rifle()
{
	CHelpers::GetClass<UMatineeCameraShake>(&CameraShakeClass, "Blueprint'/Game/Weapons/Rifle/BP_CameraShake_Rifle.BP_CameraShake_Rifle_C'");
}

void ACDoAction_Rifle::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Rifle]->Weapon;
}