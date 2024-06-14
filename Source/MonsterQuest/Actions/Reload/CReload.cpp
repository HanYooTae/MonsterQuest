#include "Actions/Reload/CReload.h"

#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CStatusComponent.h"
#include "ActorComponents/CActionComponent.h"

#include "Actions/DoActions/CDoAction_Fire.h"

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

	if (!!Data.ReloadMontage)
	{
		OwnerCharacter->PlayAnimMontage(Data.ReloadMontage, Data.PlayRate, Data.StartSection);
	}
}

void ACReload::Eject_Magazine()
{
}

void ACReload::Spawn_Magazine()
{
}

void ACReload::Load_Magazine()
{
}

void ACReload::End_Reload()
{
	bReload = false;
}
