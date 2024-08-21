#include "Notifies/CAnimNotify_Hitted.h"

#include "ActorComponents/CStateComponent.h"
#include "ActorComponents/CStatusComponent.h"

#include "Global.h"

FString UCAnimNotify_Hitted::GetNotifyName_Implementation() const
{
	return "Hitted";
}

void UCAnimNotify_Hitted::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	CheckNull(MeshComp);
	CheckNull(Animation);

	UCStateComponent* stateComp = CHelpers::GetComponent<UCStateComponent>(MeshComp->GetOwner());
	CheckNull(stateComp);
	UCStatusComponent* statusComp = CHelpers::GetComponent<UCStatusComponent>(MeshComp->GetOwner());
	CheckNull(statusComp);

	stateComp->SetIdleMode();
	statusComp->SetMove();
}