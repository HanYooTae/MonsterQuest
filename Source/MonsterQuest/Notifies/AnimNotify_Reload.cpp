#include "Notifies/AnimNotify_Reload.h"

#include "CPlayer/CPlayer.h"
#include "ActorComponents/CActionComponent.h"
#include "Actions/Reload/CReload.h"

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

	ACReload* reload = player->GetAction()->GetCurrentData()->GetReload();
	CheckNull(reload);

	switch (ActionType)
	{
	case EMagazineActionType::Eject: reload->Eject_Magazine(); break;
	case EMagazineActionType::Spawn: reload->Spawn_Magazine(); break;
	case EMagazineActionType::Load: reload->Load_Magazine(); break;
	case EMagazineActionType::End: reload->End_Reload(); break;
	}
}
