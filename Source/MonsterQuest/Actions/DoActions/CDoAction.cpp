#include "Actions/DoActions/CDoAction.h"

#include "CPlayer/CPlayer.h"
#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CStatusComponent.h"
#include "ActorComponents/CActionComponent.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACDoAction::ACDoAction()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACDoAction::BeginPlay()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	Player = Cast<ACPlayer>(OwnerCharacter);

	StatusComp = Cast<UCStatusComponent>(OwnerCharacter->GetComponentByClass(UCStatusComponent::StaticClass()));
	StateComp = Cast<UCStateComponent>(OwnerCharacter->GetComponentByClass(UCStateComponent::StaticClass()));
	ActionComp = Cast<UCActionComponent>(OwnerCharacter->GetComponentByClass(UCActionComponent::StaticClass()));

	Super::BeginPlay();
}

void ACDoAction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}