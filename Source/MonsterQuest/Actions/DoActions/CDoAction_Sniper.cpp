#include "Actions/DoActions/CDoAction_Sniper.h"

#include "CPlayer/CPlayer.h"
#include "Actions/Weapons/CWeapon.h"
#include "Actions/Reload/CReload.h"
#include "Actions/Weapons/CWeapon_Sniper.h"
#include "ActorComponents/CActionComponent.h"

#include "Components/SkeletalMeshComponent.h"

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
	Super::OnAim();

	Player->GetArms()->SetVisibility(true);
	Player->GetMesh()->SetVisibility(false);
	Player->GetBackpack()->SetVisibility(false);
	Weapon->SetHidden(true);

	AttachToComponent(Player->GetArms(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), "Sniper_AK47_RightHand");
}

void ACDoAction_Sniper::OffAim()
{
	Super::OffAim();

	Player->GetArms()->SetVisibility(false);
	Player->GetMesh()->SetVisibility(true);
	Player->GetBackpack()->SetVisibility(true);
	Weapon->SetHidden(false);
}