#include "Actions/DoActions/CDoAction.h"

#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CStatusComponent.h"

#include "GameFramework/Character.h"

#include "Global.h"

ACDoAction::ACDoAction()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACDoAction::BeginPlay()
{
	OwnerCharacter = Cast<ACharacter>(GetOwner());

	StatusComp = Cast<UCStatusComponent>(OwnerCharacter->GetComponentByClass(UCStatusComponent::StaticClass()));
	StateComp = Cast<UCStateComponent>(OwnerCharacter->GetComponentByClass(UCStateComponent::StaticClass()));

	Super::BeginPlay();
}

void ACDoAction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}