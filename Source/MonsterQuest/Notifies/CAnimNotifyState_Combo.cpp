#include "Notifies/CAnimNotifyState_Combo.h"

#include "ActorComponents/CActionComponent.h"
#include "ActionDatas/CActionData.h"
#include "Actions/DoActions/CDoAction_Sword.h"

#include "Global.h"

FString UCAnimNotifyState_Combo::GetNotifyName_Implementation() const
{
	return "Combo";
}

void UCAnimNotifyState_Combo::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* actionComp = Cast<UCActionComponent>(MeshComp->GetOwner()->GetComponentByClass(UCActionComponent::StaticClass()));
	CheckNull(actionComp);

	UCActionData_Spawned* currentData = actionComp->GetCurrentData();
	CheckNull(currentData);

	ACDoAction_Sword* doAction_Sword = Cast<ACDoAction_Sword>(currentData->GetDoAction());
	CheckNull(doAction_Sword);
	doAction_Sword->EnableCombo();
}

void UCAnimNotifyState_Combo::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* actionComp = Cast<UCActionComponent>(MeshComp->GetOwner()->GetComponentByClass(UCActionComponent::StaticClass()));
	CheckNull(actionComp);

	UCActionData_Spawned* currentData = actionComp->GetCurrentData();
	CheckNull(currentData);

	ACDoAction_Sword* doAction_Sword = Cast<ACDoAction_Sword>(currentData->GetDoAction());
	CheckNull(doAction_Sword);
	doAction_Sword->DisableCombo();
}
