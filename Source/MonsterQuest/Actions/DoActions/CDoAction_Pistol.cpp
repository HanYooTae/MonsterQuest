#include "Actions/DoActions/CDoAction_Pistol.h"

#include "Actions/Weapons/CWeapon.h"
#include "ActorComponents/CActionComponent.h"

#include "global.h"

ACDoAction_Pistol::ACDoAction_Pistol()
{
	CHelpers::GetClass<UMatineeCameraShake>(&CameraShakeClass, "Blueprint'/Game/Weapons/Pistol/BP_CameraShake_Pistol.BP_CameraShake_Pistol_C'");
}

void ACDoAction_Pistol::BeginPlay()
{
	Super::BeginPlay();

	Weapon = ActionComp->DataAssets[(int8)EActionType::Pistol]->Weapon;
}