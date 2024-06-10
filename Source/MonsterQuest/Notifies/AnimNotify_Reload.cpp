#include "Notifies/AnimNotify_Reload.h"

#include "CPlayer/CPlayer.h"
#include "Actions/Weapons/CWeapon.h"

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

	
}
