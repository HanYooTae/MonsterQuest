#include "Notifies/CAnimNotifyState_SwordEquip.h"

#include "ActorComponents/CActionComponent.h"
#include "ActionDatas/CActionData.h"
#include "Actions/Equipment/CEquipment.h"

#include "Global.h"

FString UCAnimNotifyState_SwordEquip::GetNotifyName_Implementation() const
{
	return "Sword_Equip";
}

void UCAnimNotifyState_SwordEquip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* actionComp = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(actionComp);

	UCActionData_Spawned* currentData = actionComp->GetCurrentData();
	CheckNull(currentData);

	ACEquipment* equipment = currentData->GetEquipment();
	CheckNull(equipment);

	equipment->Begin_Sword_Equip();
}

void UCAnimNotifyState_SwordEquip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* actionComp = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(actionComp);

	UCActionData_Spawned* currentData = actionComp->GetCurrentData();
	CheckNull(currentData);

	ACEquipment* equipment = currentData->GetEquipment();
	CheckNull(equipment);

	equipment->End_Equip();
}