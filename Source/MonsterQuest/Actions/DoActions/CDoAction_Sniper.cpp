#include "Actions/DoActions/CDoAction_Sniper.h"

#include "Actions/Weapons/CWeapon.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACDoAction_Sniper::ACDoAction_Sniper()
{
	CHelpers::GetClass<UMatineeCameraShake>(&CameraShakeClass, "Blueprint'/Game/Weapons/Sniper/BP_CameraShake_Sniper.BP_CameraShake_Sniper_C'");
}

void ACDoAction_Sniper::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Sniper]->Weapon;
}