#include "Notifies/AnimNotify_Reload.h"

#include "CPlayer/CPlayer.h"
#include "Actions/DoActions/CDoAction.h"

#include "Global.h"

FString UAnimNotify_Reload::GetNotifyName_Implementation() const
{
	return "Reload";
}

void UAnimNotify_Reload::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);

	CheckNull(MeshComp);
	CheckNull(Animation);

	ACPlayer* player = Cast<ACPlayer>(MeshComp->GetOwner());
	CheckNull(player);

	ACDoAction* doAction = player->GetAction()->GetCurrentData()->GetDoAction();
	CheckNull(doAction);

	switch (ActionType)
	{
	case EMagazineActionType::Eject: doAction->Eject_Magazine(); break;
	case EMagazineActionType::Spawn: doAction->Spawn_Magazine(); break;
	case EMagazineActionType::Load: doAction->Load_Magazine(); break;
	case EMagazineActionType::End: doAction->End_Reload(); break;
	}
}
