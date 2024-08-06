#include "ItemDatas/CDropItem_Sniper.h"

#include "Global.h"

ACDropItem_Sniper::ACDropItem_Sniper()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skeletalMesh(TEXT("SkeletalMesh'/Game/Weapons/Sniper/SK_KA47.SK_KA47'"));
	if (skeletalMesh.Succeeded())
	{
		SkeletalMesh->SetSkeletalMesh(skeletalMesh.Object);
	}
}