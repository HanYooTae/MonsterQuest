#include "Notifies/CAnimNotify_BeginAction.h"

#include "ActorComponents/CActionComponent.h"
#include "ActionDatas/CActionData.h"
#include "Actions/DoActions/CDoAction.h"

#include "Global.h"

FString UCAnimNotify_BeginAction::GetNotifyName_Implementation() const
{
	return "BeginAction";
}

void UCAnimNotify_BeginAction::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* actionComp = Cast<UCActionComponent>(MeshComp->GetOwner()->GetComponentByClass(UCActionComponent::StaticClass()));
	CheckNull(actionComp);

	UCActionData_Spawned* currentData = actionComp->GetCurrentData();
	CheckNull(currentData);

	ACDoAction* doAction = currentData->GetDoAction();
	CheckNull(doAction);

	doAction->Begin_DoAction();
}
