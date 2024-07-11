#include "Actions/DoActions/CDoAction_Sniper.h"

#include "CPlayer/CPlayer.h"
#include "Actions/Weapons/CWeapon.h"
#include "Actions/Reload/CReload.h"
#include "Actions/Weapons/CWeapon_Sniper.h"
#include "ActorComponents/CActionComponent.h"
#include "Widgets/HUD/CUserWidget_CrossHair.h"

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

	Player->GetMesh()->SetVisibility(false);
	Player->GetBackpack()->SetVisibility(false);
	Player->GetDotSight()->SetVisibility(true);
	Player->CrossHair->SetVisibility(ESlateVisibility::Hidden);
	Weapon->SetHidden(true);
	ActionComp->DataAssets[(int8)EActionType::Sword]->Weapon->SetHidden(true);
	ActionComp->DataAssets[(int8)EActionType::Pistol]->Weapon->SetHidden(true);
	ActionComp->DataAssets[(int8)EActionType::Rifle]->Weapon->SetHidden(true);
}

void ACDoAction_Sniper::OffAim()
{
	Super::OffAim();

	Player->GetMesh()->SetVisibility(true);
	Player->GetBackpack()->SetVisibility(true);
	Player->GetDotSight()->SetVisibility(false);
	Player->CrossHair->SetVisibility(ESlateVisibility::Visible);
	Weapon->SetHidden(false);
	ActionComp->DataAssets[(int8)EActionType::Sword]->Weapon->SetHidden(false);
	ActionComp->DataAssets[(int8)EActionType::Pistol]->Weapon->SetHidden(false);
	ActionComp->DataAssets[(int8)EActionType::Rifle]->Weapon->SetHidden(false);
}