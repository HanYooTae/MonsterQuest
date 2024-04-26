#include "Notifies/CAnimNotifyState_Collision.h"

#include "ActorComponents/CActionComponent.h"
#include "Actions/Weapons/CWeapon.h"
#include "ActionDatas/CActionData_Spawned.h"
#include "Actions/DoActions/CDoAction_Sword.h"

#include "Global.h"

FString	UCAnimNotifyState_Collision::GetNotifyName_Implementation() const
{
	return "Collision";
}

void UCAnimNotifyState_Collision::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);

	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* actionComp = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(actionComp);

	UCActionData_Spawned* currentData = actionComp->GetCurrentData();
	CheckNull(currentData);

	ACWeapon* weapon = currentData->GetWeapon();
	CheckNull(weapon);

	weapon->OnCollision();
}

void UCAnimNotifyState_Collision::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCActionComponent* actionComp = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(actionComp);

	UCActionData_Spawned* currentData = actionComp->GetCurrentData();
	CheckNull(currentData);

	ACWeapon* weapon = currentData->GetWeapon();
	CheckNull(weapon);

	weapon->OffCollision();

	ACDoAction_Sword* doAction_Sword = Cast<ACDoAction_Sword>(currentData->GetDoAction());
	CheckNull(doAction_Sword);

	// 다단히트 방지
	doAction_Sword->ClearHittedCharacters();
}