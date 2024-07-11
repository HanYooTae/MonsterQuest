#include "Actions/Reload/CReload.h"

#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CStatusComponent.h"
#include "ActorComponents/CActionComponent.h"

#include "ActionDatas/CActionData.h"
#include "Actions/Weapons/CWeapon.h"
#include "Actions/DoActions/CDoAction_Fire.h"

#include "Actions/Weapons/CMagazine.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACReload::ACReload() {}

void ACReload::BeginPlay()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());

	StatusComp = Cast<UCStatusComponent>(OwnerCharacter->GetComponentByClass(UCStatusComponent::StaticClass()));
	StateComp = Cast<UCStateComponent>(OwnerCharacter->GetComponentByClass(UCStateComponent::StaticClass()));
	ActionComp = Cast<UCActionComponent>(OwnerCharacter->GetComponentByClass(UCActionComponent::StaticClass()));

	Super::BeginPlay();
}

void ACReload::Reload()
{
	bReload = true;

	ActionComp->GetCurrentData()->GetDoAction()->End_DoAction();

	if (!!ReloadData.ReloadMontage)
	{
		OwnerCharacter->PlayAnimMontage(ReloadData.ReloadMontage, ReloadData.PlayRate, ReloadData.StartSection);
	}
}

void ACReload::Eject_Magazine()
{
	CheckNull(ReloadData.MagazineClass);

	FTransform transform = Weapon->Weapon->GetSocketTransform(ReloadData.MagazineBoneName);

	ACMagazine* magazine = GetWorld()->SpawnActorDeferred<ACMagazine>(ReloadData.MagazineClass, transform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	magazine->Eject();
	magazine->SetLifeSpan(5);
	magazine->FinishSpawning(transform);
}

void ACReload::End_Reload()
{
	bReload = false;
}
